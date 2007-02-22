// __BEGIN_LICENSE__
// 
// Copyright (C) 2006 United States Government as represented by the
// Administrator of the National Aeronautics and Space Administration
// (NASA).  All Rights Reserved.
// 
// Copyright 2006 Carnegie Mellon University. All rights reserved.
// 
// This software is distributed under the NASA Open Source Agreement
// (NOSA), version 1.3.  The NOSA has been approved by the Open Source
// Initiative.  See the file COPYING at the top of the distribution
// directory tree for the complete NOSA document.
// 
// THE SUBJECT SOFTWARE IS PROVIDED "AS IS" WITHOUT ANY WARRANTY OF ANY
// KIND, EITHER EXPRESSED, IMPLIED, OR STATUTORY, INCLUDING, BUT NOT
// LIMITED TO, ANY WARRANTY THAT THE SUBJECT SOFTWARE WILL CONFORM TO
// SPECIFICATIONS, ANY IMPLIED WARRANTIES OF MERCHANTABILITY, FITNESS FOR
// A PARTICULAR PURPOSE, OR FREEDOM FROM INFRINGEMENT, ANY WARRANTY THAT
// THE SUBJECT SOFTWARE WILL BE ERROR FREE, OR ANY WARRANTY THAT
// DOCUMENTATION, IF PROVIDED, WILL CONFORM TO THE SUBJECT SOFTWARE.
// 
// __END_LICENSE__

/// \file DiskImageResourceJP2.h
/// 
/// Provides support for the JPEG2000 image file format.
///
#ifndef __VW_FILEIO_DISK_IMAGE_RESOUCE_JP2_H__
#define __VW_FILEIO_DISK_IMAGE_RESOUCE_JP2_H__

#include <map>
#include <string>
#include <fstream>

#include <iostream>			   // debugging

#include <vw/Image/PixelTypes.h>
#include <vw/FileIO/DiskImageResource.h>

namespace vw
{
  class DiskImageResourceJP2 : public DiskImageResource
  {
  public:

    DiskImageResourceJP2(std::string const& filename)
      : DiskImageResource(filename)
    {
      open(filename);
    }
    DiskImageResourceJP2(std::string const& filename, 
			 ImageFormat const& format)
      : DiskImageResource(filename)
    {
      std::cout << "DiskImageResourceJP2::DiskImageResourceJP2(): enter" << std::endl;
      create(filename, format);
      std::cout << "DiskImageResourceJP2::DiskImageResourceJP2(): return" << std::endl;
    }
    virtual ~DiskImageResourceJP2();
    
    virtual void read(ImageBuffer const& dest, BBox2i const& bbox) const;
    virtual void write(ImageBuffer const& dest, BBox2i const& bbox);
    virtual void flush();
    std::string get_comment() const;
    void set_comment(std::string comment);
    void open(std::string const& filename);
    void create(std::string const& filename, ImageFormat const& format);
    static DiskImageResource* construct_open(std::string const& filename);
    static DiskImageResource* construct_create(std::string const& filename,
					       ImageFormat const& format);

  private:

    std::string m_filename;
    std::string m_comment;
    int m_image_data_offset;
    bool m_is_other_endian;
  };

} // namespace vw

#endif // __VW_FILEIO_DISK_IMAGE_RESOUCE_JP2_H__
