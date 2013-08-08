/*
===========================================================================

Daemon GPL Source Code
Copyright (C) 2013 Unvanquished Developers

This file is part of the Daemon GPL Source Code (Daemon Source Code).

Daemon Source Code is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

Daemon Source Code is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with Daemon Source Code.  If not, see <http://www.gnu.org/licenses/>.

===========================================================================
*/

#include "LineEditData.h"

#include <string.h>

//TODO: use a std::string instead of a fixed size char* ?
//TODO: support MAJ-selection ?

namespace Util {
    LineEditData::LineEditData(int size, int scrollSize)
    :scrollSize(scrollSize), width(size) {
    }
    const std::u32string& LineEditData::GetText() const {
        return buffer;
    }

    const char32_t* LineEditData::GetViewText() const {
        return GetText().c_str() + scroll;
    }

    int LineEditData::GetViewStartPos() const {
        return scroll;
    }

    int LineEditData::GetCursorPos() const {
        return cursor;
    }

    int LineEditData::GetViewCursorPos() const {
        return cursor - scroll;
    }

    void LineEditData::SetText(std::u32string text) {
        buffer = std::move(text);
        cursor = buffer.size();
        if (cursor > width) {
            scroll = cursor - width + scrollSize;
        } else
            scroll = 0;
    }

    void LineEditData::CursorLeft() {
        if (cursor > 0) {
            cursor --;
            UpdateScroll();
        }
    }

    void LineEditData::CursorRight() {
        if (cursor < buffer.size()) {
            cursor ++;
            UpdateScroll();
        }
    }

    void LineEditData::CursorStart() {
        cursor = 0;
        scroll = 0;
    }

    void LineEditData::CursorEnd() {
        cursor = buffer.size();
        UpdateScroll();
    }

    void LineEditData::SetCursor(int pos) {
        cursor = pos;
        UpdateScroll();
    }

    void LineEditData::DeleteNext() {
        if (cursor < buffer.size()) {
            buffer.erase(buffer.begin() + cursor);
        }
    }

    void LineEditData::DeletePrev() {
        if (cursor > 0) {
            CursorLeft();
            DeleteNext();
        }
    }

    void LineEditData::AddChar(char32_t a) {
        buffer.insert(buffer.begin() + cursor, a);
        cursor ++;
        UpdateScroll();
    }

    void LineEditData::Clear() {
        buffer.clear();
        scroll = 0;
        cursor = 0;
    }

    void LineEditData::SetWidth(int width_) {
        width = width_;
        UpdateScroll();
    }

    int LineEditData::GetWidth() const {
        return width;
    }

    void LineEditData::UpdateScroll() {
        if (cursor < scroll) {
            scroll = std::min(scroll - scrollSize, 0);
        } else if (cursor > scroll + width) {
            scroll = cursor - width + scrollSize;
        }
    }
}