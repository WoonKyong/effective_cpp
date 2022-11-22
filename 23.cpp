// 항목 23 : 멤버 함수보다는 비멤버 비프렌드 함수와 더 가까워지자
#include <iostream>
using namespace std;

class WebBrowser {
    public:
    void clearCache() {}
    void clearHistory() {}
    void removeCookies() {}
    /* 
    void clearBrowser() {
        clearCache();
        clearHistory();
        removeCookies();
    */
};

namespace WebBrowserStuff{
    void clearBrowser(WebBrowser& wb) {
        wb.clearCache();
        wb.clearHistory();
        wb.removeCookies();
    }
}


int main() {
    WebBrowser wb;
    WebBrowserStuff::clearBrowser(wb);
}

