/*
 *  This file is part of kde-thumbnailer-qoi
 *  Copyleft (C) 2022 tobozo
 *
 *  This program is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation; either version 2 of
 *  the License or (at your option) version 3 or any later version
 *  accepted by the membership of KDE e.V. (or its successor approved
 *  by the membership of KDE e.V.), which shall act as a proxy
 *  defined in Section 14 of version 3 of the license.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "qoicreator.h"

#include <QImage>

#define QOI_IMPLEMENTATION
#include "qoi/qoi.h"

extern "C" {
    Q_DECL_EXPORT ThumbCreator* new_creator() {
        return new QOICreator;
    }
}


QOICreator::QOICreator() { }
QOICreator::~QOICreator() { }

bool QOICreator::create( const QString& path, int width, int height, QImage& img )
{
    QByteArray ba = path.toLocal8Bit();
    const char *path_c_str = ba.data();

    qoi_desc desc;
    void *pixels = qoi_read((const char *)path_c_str, &desc, 0);
    int channels = desc.channels;
    int w = desc.width;
    int h = desc.height;

    QImage::Format fmt = QImage::Format_RGB888;
    switch( channels ) {
      case 3: fmt = QImage::Format_RGB888;
        break;
      case 4: fmt = QImage::Format_ARGB32;
        break;
      default: // uh-oh
        fmt = QImage::Format_RGB888;
        break;
    }

    QImage out_img((unsigned char*)pixels,w,h,fmt);
    img = out_img.rgbSwapped(); // WARNING: this is slow and inverting from qoi.h can be done at no cost
    img = img.scaled(width, height,Qt::KeepAspectRatio);
    return true;
}
