/**
 * cppcms-skeleton a set of tools and code over cppcms
 * Copyright (C) 2013 Allan SIMON <allan.simon@supinfo.com>
 * 
 * Permission is hereby granted, free of charge, to any person
 * obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without
 * restriction, including without limitation the rights to use,
 * copy, modify, merge, publish, distribute, sublicense, and/or
 * sell copies of the Software, and to permit persons to whom
 * the Software is furnished to do so, subject to the following
 * conditions:
 * 
 * The above copyright notice and this permission notice shall
 * be included in all copies or substantial portions of the
 * Software.
 * 
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY
 * KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
 * WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR
 * PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS
 * OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR
 * OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
 * OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 * SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Controllers
 * @license  MIT
 * @link     https://github.com/allan-simon/cppcms-skeleton
 *
 */


#include <fstream>

#include <cppcms/http_response.h>
#include <cppcms/session_interface.h>
#include <cppcms_skel/generics/Config.h>
#include "Img.h"



//%%%NEXT_INC_MODEL_CTRL_MARKER%%%


namespace controllers {
namespace webs {

Img::Img(cppcms::service& serv) :
    controllers::webs::Controller(serv)
{
    dispatcher().assign("/([a-z_0-9/\\.]+.(jpg|jpeg|png))[0-9]*", &Img::serve_file, this, 1, 2);

    //%%%NEXT_ACTION_DISPATCHER_MARKER%%%, do not delete

    //%%%NEXT_NEW_MODEL_CTRL_MARKER%%%
}

void Img::serve_file(
    std::string imgFile,
    std::string mimeType
) {
    std::string absolutePath = Config::get_inner_img_folder() + imgFile;
    std::ifstream file(
        absolutePath.c_str()
    );  
    if(!file.good()) {  
       response().status(404);
       response().out() << "404";
    }  
    else {  
        // jpg and jpeg are equivalent but only the mime type image/jpeg is
        // legal
        if (mimeType == "jpg") {
            mimeType = "jpeg";
        }
        response().content_type(std::string("image/") + mimeType );
        response().out() << file.rdbuf();  
    }  

    file.close();
}



/**
 *
 */
Img::~Img() {
    //%%%NEXT_DEL_MODEL_CTRL_MARKER%%%
}

// %%%NEXT_ACTION_MARKER%%% , do not delete




} // End namespace webs
} // End namespace controllers
