/**
 * Copyright (C) 2012-2013 Allan SIMON (Sysko) <allan.simon@supinfo.com>
 * See accompanying file COPYING.TXT file for licensing details.
 *
 * @category Cppcms-skeleton
 * @author   Allan SIMON <allan.simon@supinfo.com>
 * @package  Generics
 *
 */

#ifndef CPPCMS_SKEL_CONTENT_CONFIG_H
#define CPPCMS_SKEL_CONTENT_CONFIG_H

#include <map>
#include <cppcms/json.h>
#include "cppcms_skel/generics/Singleton.h"

/**
 * Singleton class that store some value used in html generation
 * such as the path for css files etc.
 */ 
class Config : public Singleton<Config> {
    friend class Singleton<Config>;

    private:

        /**
         * Default constructor, do nothing for the moment
         */
        Config();

        /**
         * @brief Store the base domain name
         *
         * @since 28 December 2012
         */
        std::string baseHost;

        /**
         * @brief Store the path for css files as displayed on the webpage
         *
         * @since 18 January 2013
         */
        std::string cssPath;

 

        /**
         * @brief Store the path for images files as used in the HTML
         * @since 19 January 2013
         */
        std::string imgPath;

        /**
         * @brief Store the path for javascript files as used in the HTML
         * @since 20 March 2013
         */
        std::string jsPath;
        

        /**
         * @brief Store the URL for uploaded files as used in the HTML
         * @since 07 June 2013
         */
        std::string uploadUrl;




        /**
         * @brief Store the path for css files on the server
         *        (if the application itself server the CSS)
         *
         * @since 18 January 2013
         */
         std::string innerCssFolder;

        /**
         * @brief Store the path for image files on the server
         *        (if the application itself server the images)
         *
         * @since 19 January 2013
         */
         std::string innerImgFolder;

        /**
         * @brief Store the path for javascript files on the server
         *        (if the application itself server the images)
         *
         * @since 20 March 2013
         */
         std::string innerJsFolder;


        /**
         * @brief Store the internal path for the uploaded file on the
         *        server 
         * @since 7 June 2013
         */
        std::string uploadFolder;



    public:
        /**
         * @brief Set the values used by the config singleton
         *        using the part of the config json dedicated
         *        to it 
         *
         * @param appConfig The json array containing the configuration
         *
         * @param 07 June 2013
         */
        static void set_values(cppcms::json::value appConfig);

        static std::string get_base_host();

        static void set_base_host(const std::string & baseHost);

        static std::string get_inner_css_folder();

        static void set_inner_css_folder(
            const std::string & cssFolder
        );

        static std::string get_css_path();

        static void set_css_path(const std::string & cssPath);


        static std::string get_inner_img_folder();

        static void set_inner_img_folder(
            const std::string & imgFolder
        );

        static std::string get_img_path();

        static void set_img_path(const std::string & imgPath);


        static std::string get_inner_js_folder();

        static void set_inner_js_folder(
            const std::string & jsFolder
        );

        static std::string get_js_path();

        static void set_js_path(const std::string & jsPath);

        static std::string get_upload_url();
        static void set_upload_url(const std::string &uploadUrl);

        static std::string get_upload_folder();
        static void set_upload_folder(const std::string &uploadFolder);

        /**
         * Store the root URL of the website
         */
        std::string webPath;


        /**
         * Store the path where the sqlite3 database is stored
         */
        std::string sqlite3Path;
};

#endif


