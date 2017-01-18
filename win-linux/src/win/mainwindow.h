/*
 * (c) Copyright Ascensio System SIA 2010-2017
 *
 * This program is a free software product. You can redistribute it and/or
 * modify it under the terms of the GNU Affero General Public License (AGPL)
 * version 3 as published by the Free Software Foundation. In accordance with
 * Section 7(a) of the GNU AGPL its Section 15 shall be amended to the effect
 * that Ascensio System SIA expressly excludes the warranty of non-infringement
 * of any third-party rights.
 *
 * This program is distributed WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR  PURPOSE. For
 * details, see the GNU AGPL at: http://www.gnu.org/licenses/agpl-3.0.html
 *
 * You can contact Ascensio System SIA at Lubanas st. 125a-25, Riga, Latvia,
 * EU, LV-1021.
 *
 * The  interactive user interfaces in modified source and object code versions
 * of the Program must display Appropriate Legal Notices, as required under
 * Section 5 of the GNU AGPL version 3.
 *
 * Pursuant to Section 7(b) of the License you must retain the original Product
 * logo when distributing the program. Pursuant to Section 7(e) we decline to
 * grant you any rights under trademark law for use of our trademarks.
 *
 * All the Product's GUI elements, including illustrations and icon sets, as
 * well as technical writing content are licensed under the terms of the
 * Creative Commons Attribution-ShareAlike 4.0 International. See the License
 * terms at http://creativecommons.org/licenses/by-sa/4.0/legalcode
 *
*/

#include <windows.h>

#include "applicationmanager.h"

#include "cwinpanel.h"
#include "qwinwidget.h"

#include <QtWidgets/QApplication>

class CMainWindow
{
    enum class Style : DWORD
    {
//        windowed        = ( WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN ),
        windowed        = ( WS_OVERLAPPED | WS_THICKFRAME | WS_CAPTION | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_CLIPCHILDREN ),
        aero_borderless = ( WS_POPUP | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_THICKFRAME | WS_CLIPCHILDREN )        
    };

public:
    HWND                    hWnd;
    HINSTANCE               hInstance;
    CAscApplicationManager* m_pManager;

    CMainWindow(CAscApplicationManager* pManager, HBRUSH windowBackground);
    ~CMainWindow();
    static LRESULT CALLBACK WndProc( HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam );
    void show(bool);
    void hide();
    bool isVisible();

    void toggleBorderless(bool);
    void toggleShadow();
    void toggleResizeable();
    bool isResizeable();

    void setMinimumSize( const int width, const int height );
    bool isSetMinimumSize();
    void removeMinimumSize();
    int getMinimumHeight();
    int getMinimumWidth();

    void setMaximumSize( const int width, const int height );
    bool isSetMaximumSize();
    int getMaximumHeight();
    int getMaximumWidth();
    void removeMaximumSize();

public:
    CWinPanel * m_pWinPanel;

private:

    bool closed;
    bool visible;

    bool borderless;
    bool aeroShadow;
    bool borderlessResizeable;

    struct sizeType
    {
        sizeType() : required( false ), width( 0 ), height( 0 ) {}

        bool required;
        int width;
        int height;
    };

    sizeType minimumSize;
    sizeType maximumSize;

    UINT_PTR m_nTimerLanguageId;
};
