#include "wintoastlib.h"

using namespace WinToastLib;

class WinToastHandler : public WinToastLib::IWinToastHandler
{
public:
    WinToastHandler(CDialogEx* pDialog) : m_pDialog(pDialog) {}
    // Public interfaces
    void toastActivated() const override {}
    void toastActivated(int actionIndex) const override {
        wchar_t buf[250];
        swprintf_s(buf, L"Button clicked: %d", actionIndex);
        m_pDialog->MessageBox(buf, L"info", MB_OK);
    }
    void toastDismissed(WinToastDismissalReason state) const override {}
    void toastFailed() const override {}
private:
    CDialogEx* m_pDialog;
};


WinToastHandler m_WinToastHandler;
WinToast::WinToastError error;
WinToast::instance()->setAppName(L"TestToastExample");
const auto aumi = WinToast::configureAUMI
                  (L"company", L"wintoast", L"wintoastexample", L"20201012");
WinToast::instance()->setAppUserModelId(aumi);

if (!WinToast::instance()->initialize(&error)) {
    wchar_t buf[250];
    swprintf_s(buf, L"Failed to initialize WinToast :%d", error);
    MessageBox(buf, L"Error");
}

enum WinToastTemplateType
{
    ImageAndText01,
    ImageAndText02,
    ImageAndText03,
    ImageAndText04,
    Text01,
    Text02,
    Text03,
    Text04,
    HeroImageAndImageAndText01,
    HeroImageAndImageAndText02,
    HeroImageAndImageAndText03,
    HeroImageAndImageAndText04,
    HeroImageAndText01,
    HeroImageAndText02,
    HeroImageAndText03,
    HeroImageAndText04,
};

WinToastTemplate templ;
if (WinToast::isWin10AnniversaryOrHigher())
{
    templ = WinToastTemplate(WinToastTemplate::HeroImageAndImageAndText02);
    bool inlineImage = false;
    templ.setHeroImagePath(L"C:\\Users\\u\\Pictures\\hero.jpg",
        inlineImage);
}
else
{
    templ = WinToastTemplate(WinToastTemplate::ImageAndText02);
}
templ.setImagePath(
    L"C:\\Users\\u\\Pictures\\pretty_gal.jpg", 
    WinToastTemplate::CropHint::Circle);

templ.setTextField(L"My First Toast", WinToastTemplate::FirstLine);
templ.setTextField(L"Say Hello?", WinToastTemplate::SecondLine);

templ.addAction(L"Yes");
templ.addAction(L"No");

// Read the additional options section in the article
templ.setDuration(WinToastTemplate::Duration::Short);
templ.setAudioOption(WinToastTemplate::AudioOption::Default);
templ.setAudioPath(WinToastTemplate::AudioSystemFile::Call1);

if (WinToast::instance()->showToast(templ, &m_WinToastHandler) == -1L)
{
    MessageBox(L"Could not launch your toast notification!", L"Error");
}
