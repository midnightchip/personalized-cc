import Cephei
import CepheiPrefs
import Preferences
import prefsC
import UIKit

@objc(AboutController) @objcMembers final class AboutController: HBAboutListController {
    override static var specifierPlist: String {
        return "About"
    }

    override static func hb_supportEmailAddress() -> String? {
        return "personalizedcc-support@midnightchips.me"
    }
}
