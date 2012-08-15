#TODO for lisibility should be better to include them in some sub naming space

# directory were the template files are stored
CTRL_TEMPLATE_DIR = "../src/controllers/webs/template"
CTRL_OUTPUT_DIR = "../src/controllers/webs"
#name of the template that contains the main template of the
# .cpp file of a controller
TMPL_CTRL_CPP = '_template_.cpp.tpl'
#name of the template that contains the main template of the
# .h file of a controller
TMPL_CTRL_H = '_template_.h.tpl'
#name of the template that contains the code for a new
#controller method
TMPL_METHOD_CPP = '_template_method.tpl'
#name of the template that contains the code for a new
#controller method header
TMPL_METHOD_H = '_template_method_header.tpl'

#template that contains the code to attach the action
#to the controller
TMPL_METHOD_DISPATCH_CPP = '_template_method_dispatcher_.tpl'

#marker to tell where to put the next method's code in the
#controller file
NEXT_ACTION_MARKER = "%%%NEXT_ACTION_MARKER%%%"
NEXT_ACTION_DISPATCHER_MARKER = "%%%NEXT_ACTION_DISPATCHER_MARKER%%%"


MAIN_APP_DIR = "../src"
MAIN_APP_TEMPLATE_DIR = "../src/code_template"

TMPL_MAIN_APP_DISPATCHER_CPP = 'controller_dispatcher.tpl'
TMPL_MAIN_APP_CONSTRUCT_CPP = 'controller_construct.tpl'

TMPL_MAIN_APP_INCLUDE_H = 'controller_header.tpl'
TMPL_MAIN_APP_ATTR_H = 'controller_header_attr.tpl'

NEXT_CONTROLLER_DISPATCHER_MARKER = '%%%NEXT_CONTROLLER_DISPATCHER_MARKER%%%'
NEXT_MAIN_APP_CTRL_CONSTRUCT_MARKER = '%%%NEXT_MAIN_APP_CTRL_CONSTRUCT_MARKER%%%'

NEXT_CONTROLLER_INCLUDE_MARKER = '%%%NEXT_CONTROLLER_INCLUDE_MARKER%%%'
NEXT_MAIN_APP_CTRL_ATTR = '%%%NEXT_MAIN_APP_CTRL_ATTR%%%'



