meta:
	ADDON_NAME = ofxWiiuse
	ADDON_DESCRIPTION = Addon to use microsoft wii devices in openframeworks
	ADDON_AUTHOR = Thomas Geissl
	ADDON_TAGS = "wii" "wiiuse"
	ADDON_URL = http://github.com/thomasgeissl/ofxWiiuse

linux64:
	ADDON_LDFLAGS = -lwiiuse -L/usr/local/lib/
osx:
#	ADDON_LDFLAGS = -lwiiuse -L/usr/local/lib/

