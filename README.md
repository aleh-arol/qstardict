**QStarDict** is a dictionary application for learning languages.

## Debian packaging

For local Debian package builds, this repository adopts the QStarDict packaging
from Debian. The Debian packaging is copyright 2007-2008 Alexander Rodin,
2018 Boyuan Yang, and 2024-2025 Alex Fomin, and is licensed under GPL-2.0 or
later. The complete attribution and licensing information is retained in
[`debian/copyright`](debian/copyright).

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

## OpenAI-compatible translation

The optional `openai` dictionary plugin translates text through an already-running
OpenAI-compatible Chat Completions API. It does not install, start, stop, or
otherwise manage models or API services.

Configure the plugin from the Dictionaries tab's Plugins table. Its default API
base URL is `http://127.0.0.1:8328/v3`, the default OpenAI endpoint reported by the
Gemma 3 inference snap. The endpoint is configurable because the active engine
or service may expose another URL. QStarDict verifies the API and its strict
structured-output support when you save the plugin configuration, then enables
the provider. Existing successful plugin configurations are activated once when
QStarDict starts. You can disable it later in the Dictionaries table.

The provider translates phrases only by default, leaving one-word lookups to
StarDict. Set the target language and optional translation instructions in the
plugin settings. An unavailable API is ignored silently; API and response
errors are shown in the translation result.

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
