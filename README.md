**QStarDict** is a dictionary application for learning languages.

# Main features

* Full support of StarDict 2.x dictionaries
* Working in the system tray
* Scanning mouse selection and showing a popup window with translation of
selected words
* Translations reformatting
* Pronuncation of translated words
* Pronunciation of IPA transcriptions in the translations
* Plugins support
* Training for studying words

## Text-to-speech

QStarDict uses `espeak-ng` by default for word and IPA pronunciation. Both
speech commands can be changed in the application settings to use another
text-to-speech program.

## Popup auto-hide

The popup window can close automatically after it is shown. Configure
**Timeout before hide after popup shown** in the Popup window settings. It is
disabled by default, and a new popup display restarts the timeout.

## Wayland popup toggle

Wayland does not allow QStarDict to read the primary selection globally. The
packaged desktop launcher starts QStarDict through XWayland. To start it from
a terminal, use:

```bash
env QT_QPA_PLATFORM=xcb qstardict
```

The `qstardict-popup-toggle` helper reads the X11 primary selection with
`xclip` and sends it to an atomic toggle operation on the session D-Bus
service. Bind `qstardict-popup-toggle` to a desktop environment global
shortcut. The first invocation shows a translation; the next hides the visible
popup.
