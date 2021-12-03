import AVFoundation
import AVKit
import ccbackgroundC
import Cephei
import Orion
import os
import UIKit

class CCUIModularControlCenterOverlayViewControllerHook: ClassHook<CCUIModularControlCenterOverlayViewController> {
    @Property(.nonatomic) var backgroundView: UIView? = nil
    @Property(.nonatomic) var player: AVPlayer? = nil
    @Property(.nonatomic) var prefs = HBPreferences(identifier: "me.midnightchips.ccbackgroundprefs")
    func viewDidLoad() {
        orig.viewDidLoad()
        backgroundView = UIView(frame: UIScreen.main.bounds)
        backgroundView?.backgroundColor = .clear
        backgroundView?.alpha = 0

        let type = prefs.integer(forKey: "selectedBackground", default: 0)

        switch type {
        case 0:
            setupNormalImage()
        case 1:
            setupGifImage()
        case 2:
            setupPlayer()
        default:
            break
        }
        target.view.insertSubview(backgroundView!, at: 1)
    }

    // orion:new
    func setupNormalImage() {
        let image = UIImage(contentsOfFile: "/var/mobile/Library/Application Support/me.midnightchips.personalizedcc/photo.png")
        let imageView = UIImageView(image: image)
        imageView.contentMode = .scaleAspectFill
        imageView.frame = UIScreen.main.bounds
        backgroundView?.addSubview(imageView)
    }

    // orion:new
    func setupGifImage() {
        let pathURL = URL(fileURLWithPath: "/var/mobile/Library/Application Support/me.midnightchips.personalizedcc/gif.gif")
        let imageURL = UIImage.gifImageWithURL(pathURL.absoluteString)
        let imageView = UIImageView(image: imageURL)
        imageView.contentMode = .scaleAspectFill
        imageView.frame = UIScreen.main.bounds
        backgroundView?.addSubview(imageView)
    }

    // orion:new
    func setupPlayer() {
        player = AVPlayer(url: URL(fileURLWithPath: "/var/mobile/Library/Application Support/me.midnightchips.personalizedcc/video.mp4"))
        let playerLayer = AVPlayerLayer(player: player)
        playerLayer.frame = UIScreen.main.bounds
        playerLayer.videoGravity = .resizeAspectFill
        backgroundView?.layer.addSublayer(playerLayer)
    }

    @objc(_beginPresentationAnimated:interactive:)
    func _beginPresentation(_ animated: Bool, interactive: Bool) {
        orig._beginPresentation(animated, interactive: interactive)
        player?.seek(to: .zero)
        player?.play()
        UIView.animate(withDuration: 0.2, animations: {
            self.backgroundView?.alpha = 1
        })
    }

    @objc(dismissAnimated:withCompletionHandler:)
    func dismiss(animated: Bool, completion: (() -> Void)?) {
        orig.dismiss(animated: animated, completion: completion)
        UIView.animate(withDuration: 0.2, delay: 0, options: .curveEaseInOut, animations: {
            self.backgroundView?.alpha = 0
            self.player?.pause()
        }, completion: nil)
    }
}
