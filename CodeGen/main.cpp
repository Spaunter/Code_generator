//-------------function main + GUI 
#include "CodeGen.h"

HFONT hFont = CreateFont(20, 0, 0, 2, FW_REGULAR, 0, 0, 0, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, CLEARTYPE_QUALITY, DEFAULT_PITCH, L"Roboto");//fonts
HWND hEditCount, hEditIdent, hEditType, hEditLenght; // input filds


int CALLBACK  wWinMain(HINSTANCE hInstance, HINSTANCE, PWSTR szCmdLine, int nCmdShow)
{
    
    MSG msg{};                           
    HWND hwnd{};                         
    WNDCLASSEX wc{ sizeof(WNDCLASSEX) }; 
    wc.cbClsExtra = 0;
    wc.cbWndExtra = 0;
    //wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(WHITE_BRUSH));
    wc.hbrBackground = GetSysColorBrush(COLOR_3DFACE);
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
    wc.hInstance = hInstance;
    wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) -> LRESULT
    {
        switch (uMsg)
        {
        case WM_CREATE:
        {   
            //-----------------------header memu-----------------------------------
            HMENU hMenuBar = CreateMenu();
            HMENU hMenuInfo = CreateMenu();
            HMENU hMenuAbout = CreateMenu();

            AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)clientElement::information, L"����������");
            AppendMenu(hMenuBar, MF_POPUP, (UINT_PTR)clientElement::aboutApp, L"� ���������");

            SetMenu(hWnd, hMenuInfo);
            SetMenu(hWnd, hMenuAbout);
            SetMenu(hWnd, hMenuBar);
           //-------------------------------------------------------------------------
           //------------------------count fild----------------------------------
            HWND hTextCount = CreateWindow(
                L"STATIC",
                L"���������� �����",
                WS_CHILD | WS_VISIBLE,
                30,20,200,30, hWnd, nullptr, nullptr, nullptr
            );
            HWND hTextCountInfo = CreateWindow(
                L"STATIC",
                L"�������� ��������",
                WS_CHILD | WS_VISIBLE,
                30, 40, 200, 30, hWnd, nullptr, nullptr, nullptr
            );
            SendMessage(hTextCount, WM_SETFONT, (WPARAM)hFont, TRUE);// font style
            hEditCount = CreateWindowEx(
                WS_EX_CLIENTEDGE,
                L"EDIT",
                L"",
                WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER,
                300, 20, 50, 30, hWnd, reinterpret_cast<HMENU>(clientElement::editCount), nullptr, nullptr
            );
           //----------------------------ident fild------------------------
            HWND hTextIdent = CreateWindow(
                L"STATIC",
                L"������������� ����",
                WS_CHILD | WS_VISIBLE,
                30, 70, 200, 30, hWnd, nullptr, nullptr, nullptr
            );
            HWND hTextIdentInfo = CreateWindow(
                L"STATIC",
                L"��������� �������� �������� a - z",
                WS_CHILD | WS_VISIBLE,
                30, 90, 200, 30, hWnd, nullptr, nullptr, nullptr
            );
            SendMessage(hTextIdent, WM_SETFONT, (WPARAM)hFont, TRUE);
            hEditIdent = CreateWindowEx(
                WS_EX_CLIENTEDGE,
                L"EDIT",
                L"",
                WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL| WS_BORDER,
                300, 70, 50, 30, hWnd, reinterpret_cast<HMENU>(clientElement::editIdent), nullptr, nullptr
            );
           //--------------------fild lenght------------------------------------
            HWND hTextLength = CreateWindow(
                L"STATIC",
                L"����� ����",
                WS_CHILD | WS_VISIBLE,
                30, 140, 200, 30, hWnd, nullptr, nullptr, nullptr
            );
            HWND hTextLengthInfo = CreateWindow(
                L"STATIC",
                L"�������� �������� 2 - 10",
                WS_CHILD | WS_VISIBLE,
                30, 160, 200, 30, hWnd, nullptr, nullptr, nullptr
            );
            SendMessage(hTextLength, WM_SETFONT, (WPARAM)hFont, TRUE);
            hEditLenght = CreateWindowEx(
                WS_EX_CLIENTEDGE,
                L"EDIT",
                L"",
                WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER,
                300, 140, 50, 30, hWnd, reinterpret_cast<HMENU>(clientElement::editLenght), nullptr, nullptr
            );
           //--------------------------fild code_type------------------------------
            HWND hTextType = CreateWindow(
                L"STATIC",
                L"��� ����",
                WS_CHILD | WS_VISIBLE,
                30, 190, 200, 30, hWnd, nullptr, nullptr, nullptr
            );
            HWND hTextTypeInfo = CreateWindow(
                L"STATIC",
                L"1 - ��������, \n2 - �����-���������",
                WS_CHILD | WS_VISIBLE,
                30, 210, 200, 35, hWnd, nullptr, nullptr, nullptr
            );
            SendMessage(hTextType, WM_SETFONT, (WPARAM)hFont, TRUE);
            hEditType = CreateWindowEx(
                WS_EX_CLIENTEDGE,
                L"EDIT",
                L"",
                WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_BORDER,
                300, 190, 50, 30, hWnd, reinterpret_cast<HMENU>(clientElement::editType), nullptr, nullptr
            );
               //------------------------------button-----------------------------------
            HWND hButton = CreateWindow(
                L"BUTTON",
                L"�������������",
                WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON| BS_BITMAP,
                120, 270, 150, 40, hWnd, reinterpret_cast<HMENU>(clientElement::button), nullptr, nullptr
            );
            SendMessage(hButton, WM_SETFONT, (WPARAM)hFont, TRUE);
            
        }
        return 0;

        
        case WM_COMMAND:
        {
            switch (LOWORD(wParam))
            {//--------------------------------------action on button-----------------------------
                case clientElement::button:
                {   
                    //-----------------get and convert data from filds-------------------------
                    wstring wStrCountCodes{};
                    wStrCountCodes.resize(MAX_LENGHT);
                    GetWindowText(hEditCount, &wStrCountCodes[0], MAX_LENGHT);
                    wStrCountCodes.erase(remove(begin(wStrCountCodes), end(wStrCountCodes), 0), end(wStrCountCodes));

                    wstring wStrCodeLength{};
                    wStrCodeLength.resize(MAX_LENGHT);
                    GetWindowText(hEditLenght, &wStrCodeLength[0], MAX_LENGHT);
                    wStrCodeLength.erase(remove(begin(wStrCodeLength), end(wStrCodeLength), 0), end(wStrCodeLength));

                    wstring wStrCodeType{};
                    wStrCodeType.resize(MAX_LENGHT);
                    GetWindowText(hEditType, &wStrCodeType[0], MAX_LENGHT);
                    wStrCodeType.erase(remove(begin(wStrCodeType), end(wStrCodeType), 0), end(wStrCodeType));

                    wstring wStrCodeIdent{};
                    wStrCodeIdent.resize(MAX_LENGHT);
                    GetWindowText(hEditIdent, &wStrCodeIdent[0], MAX_LENGHT);
                    wStrCodeIdent.erase(remove(begin(wStrCodeIdent), end(wStrCodeIdent), 0), end(wStrCodeIdent));

                    if (wStrCountCodes.empty()|wStrCodeLength.empty()|wStrCodeType.empty()| wStrCodeIdent.empty()) // ���� ���� ������ ����
                    {
                        MessageBox(hWnd, L"��� ���� ������ ���� ���������!", L"������", MB_ICONERROR);
                        break;
                    }
                    else 
                    {// if filds ant empty
                        //----------------------- convert wstring � string--------------------
                        string strCounCodes(wStrCountCodes.begin(), wStrCountCodes.end()); 
                        string strCodeLenght(wStrCodeLength.begin(), wStrCodeLength.end());
                        string strCodeIdent(wStrCodeIdent.begin(), wStrCodeIdent.end());
                        string strCodeType(wStrCodeType.begin(), wStrCodeType.end());
                       //---------------------checking input data---------------------------
                        if (atoi(strCounCodes.c_str()) < 1||!regex_match(strCounCodes, regNum))
                        {
                            MessageBox(hWnd, L"�������� ������ ����������:\n������ ������ ��������� ������ ������������� �����.",nullptr, MB_ICONERROR);
                            SetWindowText(hEditCount, nullptr);
                            break;
                        }
                        if (atoi(strCodeLenght.c_str()) < 2 || atoi(strCodeLenght.c_str()) > 10 || !regex_match(strCodeLenght, regNum)) 
                        {
                            MessageBox(hWnd, L"�������� ������ ����� ����:\n������ ������ ��������� ������ ������������� ����� � ��������� �� 2 �� 10 ������������.",nullptr, MB_ICONERROR);
                            SetWindowText(hEditLenght, nullptr);
                            break;
                        }
                        if (!regex_match(strCodeIdent, regLetter))
                        {
                            MessageBox(hWnd, L"�������� ������������� ����:\n ����� ������ ��������� ��������� ����� a-z.", nullptr , MB_ICONERROR);
                            SetWindowText(hEditIdent, nullptr);
                            break;
                        }
                        if (atoi(strCodeType.c_str()) < 1 || atoi(strCodeType.c_str()) > 2 || !regex_match(strCodeType, regNum))
                        {
                            MessageBox(hWnd, L"�������� ������ ����:\n1 - �������� ������;\n2 - ���po-�y��e����.", nullptr, MB_ICONERROR);
                            SetWindowText(hEditType, nullptr);
                            break;
                        }
                        else{
                            int counCodes = atoi((to_string(stoi(wStrCountCodes))).c_str());
                            int codeLenght = atoi((to_string(stoi(wStrCodeLength))).c_str());
                            int codeType = atoi((to_string(stoi(wStrCodeType))).c_str());
                            string ident(wStrCodeIdent.begin(), wStrCodeIdent.end());

                            MessageBox(hWnd, L"������� � ���������, �� ���������� ����������!", L"��������", MB_ICONINFORMATION);

                            if (saveFile(codeGen(ident, codeLenght, counCodes, codeType), ident)) { 
                                MessageBox(hWnd, L"��� ���� ����� � ��������� �� ������� �����", L"������", MB_ICONINFORMATION);
                            }
                          
                        }
                   
                    }
                   
                }
                break;
                //----------------------check on push header button-------------------------
                case clientElement::aboutApp: {
                    MessageBox(hWnd, L"CODE GENERATOR v 1.0 \n\nby Maksym Homenko", L"O ���������", MB_OK); 
                }
                break;
                case clientElement::information: {
                    MessageBox(hWnd, L"��������� ����� ��� �����:\
                    \n\n1. ���������� �����: ���� ������ ��������� ������ ������������� �������� ��������;\
                    \n\n2. �������������: ���� ������ ��������� ��������� ��������� �������� ���������� �������� a-z;\
                    \n\n3. ����� ����: ���� ������ ��������� �������� �� 2 �� 10, �� ��������, ��� ������ ������ - �������������;\
                    \n\n4. ��� ����: ���� ������ ��������� �������� �������� 1 ��� 2, 1 - �������� ���, 2 - �����-���������.", L"����������", MB_OK);
                }
                break;

            }
        
        }
        return 0;

        case WM_DESTROY:
        {
            PostQuitMessage(EXIT_SUCCESS);
        }
        return 0;

        }
        return DefWindowProc(hWnd, uMsg, wParam, lParam); 
    };
    wc.lpszClassName = L"MyAppClass";
    wc.lpszMenuName = nullptr;
    wc.style = CS_VREDRAW | CS_HREDRAW;
  
    if (!RegisterClassEx(&wc)) { return EXIT_FAILURE; }
       
    hwnd = CreateWindow(wc.lpszClassName, L"CodeGen", /*WS_OVERLAPPEDWINDOW*/ WS_SYSMENU/*only close*/, 700, 300, 400, 400, nullptr, nullptr, wc.hInstance, nullptr);
    if ( hwnd == INVALID_HANDLE_VALUE){ return EXIT_FAILURE;}
        
   
    ShowWindow(hwnd, nCmdShow); 
    UpdateWindow(hwnd);          

    while (GetMessage(&msg, nullptr, 0, 0)) 
    {
        TranslateMessage(&msg); 
        DispatchMessage(&msg);  
    }

    return static_cast<int> (msg.wParam); 

};

