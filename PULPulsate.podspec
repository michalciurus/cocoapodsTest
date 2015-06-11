#
# Be sure to run `pod lib lint PULPulsate.podspec' to ensure this is a
# valid spec and remove all comments before submitting the spec.
#
# Any lines starting with a # are optional, but encouraged
#
# To learn more about a Podspec see http://guides.cocoapods.org/syntax/podspec.html
#

Pod::Spec.new do |s|
  s.name             = "PULPulsate"
  s.version          = "0.2.0"
  s.summary          = "Pulsate SDK"

  s.homepage         = "http://pulsatehq.com/"

  s.license          = 'MIT'
  s.author           = { "Pulsate" => "http://pulsatehq.com/" }
  s.source           = { :git => "https://github.com/<GITHUB_USERNAME>/PULPulsate.git", :tag => s.version.to_s }

  s.platform     = :ios, '7.0'
  s.requires_arc = true
  s.ios.vendored_frameworks = 'PulsateSDK/PULPulsate.framework'
  s.resource = 'PulsateSDK/PULPulsate.bundle'
  s.frameworks = 'CoreData' , 'SystemConfiguration', 'CoreLocation'
  s.weak_framework = 'UIKit'
  s.library = 'z'

  # s.public_header_files = 'Pod/Classes/**/*.h'
  # s.frameworks = 'UIKit', 'MapKit'
  # s.dependency 'AFNetworking', '~> 2.3'
end
