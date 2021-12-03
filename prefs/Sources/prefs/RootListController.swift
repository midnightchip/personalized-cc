import AVFoundation
import AVKit
import Cephei
import CepheiPrefs
import Preferences
import prefsC

class RootListController: HBListController, UIImagePickerControllerDelegate & UINavigationControllerDelegate {
    let prefs = HBPreferences(identifier: "me.midnightchips.ccbackgroundprefs")
    let center = MRYIPCCenter(named: "com.midnightchips.writeanywhere")
    var player: AVPlayer?
    var backgroundType: PSSpecifier?
    var photoSpec: PSSpecifier?
    var gifSpec: PSSpecifier?
    var videoSpec: PSSpecifier?
    override var specifiers: NSMutableArray? {
        get {
            if let specifiers = value(forKey: "_specifiers") as? NSMutableArray {
                return specifiers
            } else {
                let specifiers = loadSpecifiers(fromPlistName: "Root", target: self)
                setValue(specifiers, forKey: "_specifiers")
                backgroundType = specifier(forID: "selectedBackground")
                photoSpec = specifier(forID: "selectPhoto")
                gifSpec = specifier(forID: "selectGif")
                videoSpec = specifier(forID: "selectVideo")
                return specifiers
            }
        }
        set {
            super.specifiers = newValue
        }
    }

    func updateSpecifiersVisibility(animated: Bool) {
        let switchVal = prefs.integer(forKey: "selectedBackground", default: 0)
        // removeContiguousSpecifiers([photoSpec!, gifSpec!, videoSpec!], animated: animated)
        removeSpecifier(photoSpec!, animated: animated)
        removeSpecifier(gifSpec!, animated: animated)
        removeSpecifier(videoSpec!, animated: animated)

        switch switchVal {
        case 0:
            insertContiguousSpecifiers([photoSpec!], after: backgroundType, animated: animated)
        case 1:
            insertContiguousSpecifiers([gifSpec!], after: backgroundType, animated: animated)
        case 2:
            insertContiguousSpecifiers([videoSpec!], after: backgroundType, animated: animated)
        default:
            break
        }

        updateHeader()
    }

    override func setPreferenceValue(_ value: Any!, specifier: PSSpecifier!) {
        super.setPreferenceValue(value, specifier: specifier)

        updateSpecifiersVisibility(animated: true)
    }

    override func reloadSpecifiers() {
        super.reloadSpecifiers()
        updateSpecifiersVisibility(animated: true)
    }

    override func viewDidLayoutSubviews() {
        super.viewDidLayoutSubviews()
        sizeHeaderToFit()
    }

    override func viewDidLoad() {
        super.viewDidLoad()
        updateSpecifiersVisibility(animated: true)
    }

    override func loadView() {
        super.loadView()
        navigationItem.rightBarButtonItem = UIBarButtonItem(title: "Respring", style: .plain, target: self, action: #selector(respring))
    }

    private func updateHeader() {
        let type = prefs.integer(forKey: "selectedBackground", default: 0)
        if type == 0 {
            createImageHeader()

        } else if type == 1 {
            createGifHeader()

        } else {
            createVideoHeader()
        }

        sizeHeaderToFit()
    }

    private func createImageHeader() {
        let image = UIImage(contentsOfFile: "/var/mobile/Library/Application Support/me.midnightchips.personalizedcc/photo.png")
        let imageView = UIImageView(image: image)
        imageView.contentMode = .scaleAspectFit
        imageView.frame = CGRect(x: 0, y: 0, width: table.frame.size.width, height: table.frame.size.width)
        table.tableHeaderView = imageView
    }

    private func createGifHeader() {
        let pathURL = URL(fileURLWithPath: "/var/mobile/Library/Application Support/me.midnightchips.personalizedcc/gif.gif")
        let image = UIImage.gifImageWithURL(pathURL.absoluteString) // UIImage(contentsOfFile: "/var/mobile/Library/Application Support/me.midnightchips.personalizedcc/photo.png")
        let imageView = UIImageView(image: image)
        imageView.contentMode = .scaleAspectFit
        imageView.frame = CGRect(x: 0, y: 0, width: table.frame.size.width, height: table.frame.size.width)
        table.tableHeaderView = imageView
    }

    private func createVideoHeader() {
        player = AVPlayer(url: URL(fileURLWithPath: "/var/mobile/Library/Application Support/me.midnightchips.personalizedcc/video.mp4"))
        let newView = UIView(frame: CGRect(x: 0, y: 0, width: table.frame.size.width, height: table.frame.size.width))
        let layer = AVPlayerLayer(player: player)
        layer.backgroundColor = UIColor.clear.cgColor
        layer.frame = newView.layer.bounds
        layer.videoGravity = .resizeAspectFill

        newView.layer.sublayers?
            .filter { $0 is AVPlayerLayer }
            .forEach { $0.removeFromSuperlayer() }
        newView.layer.addSublayer(layer)

        table.tableHeaderView = newView
        player?.play()

        NotificationCenter.default.addObserver(forName: .AVPlayerItemDidPlayToEndTime, object: player?.currentItem, queue: .main) { [weak self] _ in
            self?.player?.seek(to: CMTime.zero)
            self?.player?.play()
        }
    }

    private func sizeHeaderToFit() {
        let headerView = table.tableHeaderView!

        headerView.setNeedsLayout()
        headerView.layoutIfNeeded()
        var frame = headerView.frame
        frame.size.height = table.frame.size.width
        headerView.frame = frame

        headerView.layer.sublayers?
            .filter { $0 is AVPlayerLayer }
            .forEach { $0.frame = headerView.bounds }

        table.tableHeaderView = headerView
    }

    @objc(selectPhoto) func selectPhoto() {
        let photoLibraryController = UIImagePickerController()
        photoLibraryController.delegate = self
        photoLibraryController.sourceType = UIImagePickerController.SourceType.photoLibrary

        photoLibraryController.mediaTypes = ["public.image"]
        photoLibraryController.allowsEditing = false

        present(photoLibraryController, animated: true, completion: nil)
    }

    @objc(selectVideo) func selectVideo() {
        let photoLibraryController = UIImagePickerController()
        photoLibraryController.delegate = self
        photoLibraryController.sourceType = UIImagePickerController.SourceType.photoLibrary

        photoLibraryController.mediaTypes = ["public.movie"]
        photoLibraryController.allowsEditing = false

        present(photoLibraryController, animated: true, completion: nil)
    }

    // UIImagePickerControllerDelegate
    func imagePickerController(_ picker: UIImagePickerController, didFinishPickingMediaWithInfo info: [UIImagePickerController.InfoKey: Any]) {
        picker.dismiss(animated: true, completion: nil)
        let type = prefs.integer(forKey: "selectedBackground", default: 0)

        var filename: String

        if type == 0 {
            filename = "photo.png"
        } else if type == 1 {
            filename = "gif.gif"
        } else {
            filename = "video.mp4"
        }

        guard let fileUrl: NSURL = info[.mediaURL] == nil ? info[.imageURL] as? NSURL : info[.mediaURL] as? NSURL else {
            return
        }
        let fileData = NSData(contentsOf: fileUrl as URL)

        let props: NSDictionary = ["fileData": fileData ?? Data(), "filePath": "/var/mobile/Library/Application Support/me.midnightchips.personalizedcc/\(filename)"]
        center?.callExternalMethod(Selector(("writeFile:")), withArguments: props)
        DispatchQueue.main.async {
            self.updateHeader()
        }
    }

    @objc func respring() {
        HBRespringController.respring()
    }
}
