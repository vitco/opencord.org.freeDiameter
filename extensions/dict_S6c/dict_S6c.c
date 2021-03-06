/*
* Copyright (c) 2017 Sprint
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*    http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*/

/****************
 Generated By: fdtool enhancements to diafuzzer
 License: same as freeDiameter
****************/


/* 
 * Dictionary definitions of objects specified in S6c (e10).
 */
#include <freeDiameter/extension.h>

#define PROTO_VER "e10"
#define GEN_DATE  1506697121.53

const char *s6c_proto_ver = PROTO_VER;
const double s6c_gen_date = GEN_DATE;

/* The content of this file follows the same structure as dict_base_proto.c */

#define CHECK_dict_new( _type, _data, _parent, _ref )                                     \
{                                                                                         \
    int _ret = fd_dict_new( fd_g_config->cnf_dict, (_type), (_data), (_parent), (_ref) ); \
    if ( _ret != 0 && _ret != EEXIST )                                                    \
       return _ret;                                                                       \
}

#define CHECK_dict_search( _type, _criteria, _what, _result )		\
    CHECK_FCT(  fd_dict_search( fd_g_config->cnf_dict, (_type), (_criteria), (_what), (_result), ENOENT) );

struct local_rules_definition {
    struct dict_avp_request avp_vendor_plus_name;
    enum rule_position	position;
    int 			min;
    int			max;
};

#define RULE_ORDER( _position ) ((((_position) == RULE_FIXED_HEAD) || ((_position) == RULE_FIXED_TAIL)) ? 1 : 0 )

/* Attention! This version of the macro uses AVP_BY_NAME_AND_VENDOR, in contrast to most other copies! */
#define PARSE_loc_rules( _rulearray, _parent) {                                                         \
        int __ar;                                                                                       \
        for (__ar=0; __ar < sizeof(_rulearray) / sizeof((_rulearray)[0]); __ar++) {                     \
                struct dict_rule_data __data = { NULL,                                                  \
                        (_rulearray)[__ar].position,                                                    \
                        0,                                                                              \
                        (_rulearray)[__ar].min,                                                         \
                        (_rulearray)[__ar].max};                                                        \
                __data.rule_order = RULE_ORDER(__data.rule_position);                                   \
                CHECK_FCT(  fd_dict_search(                                                             \
                        fd_g_config->cnf_dict,                                                          \
                        DICT_AVP,                                                                       \
                        AVP_BY_NAME_AND_VENDOR,                                                         \
                        &(_rulearray)[__ar].avp_vendor_plus_name,                                       \
                        &__data.rule_avp, 0 ) );                                                        \
                if ( !__data.rule_avp ) {                                                               \
                        TRACE_DEBUG(INFO, "AVP Not found: '%s'", (_rulearray)[__ar].avp_vendor_plus_name.avp_name);             \
                        return ENOENT;                                                                  \
                }                                                                                       \
                {                                                                                       \
                         int _ret = fd_dict_new( fd_g_config->cnf_dict, DICT_RULE, &(__data), (_parent), NULL ); \
                         if ( _ret != 0 && _ret != EEXIST )      {                                      \
                                TRACE_DEBUG(INFO, "Error on rule with AVP '%s'",                        \
                                            (_rulearray)[__ar].avp_vendor_plus_name.avp_name);          \
                                return EINVAL;                                                          \
                         }                                                                              \
                }                                                                                       \
        }                                                                                               \
}

#define CHECK_vendor_new( _data ) { \
        struct dict_object * vendor_found; \
        if (fd_dict_search(fd_g_config->cnf_dict,DICT_VENDOR,VENDOR_BY_ID,&_data.vendor_id,&vendor_found,ENOENT) == ENOENT) { \
                CHECK_FCT(fd_dict_new(fd_g_config->cnf_dict, DICT_VENDOR, &_data, NULL, NULL)); \
        } \
}

#define enumval_def_u32( _val_, _str_ )		\
    { _str_, 		{ .u32 = _val_ }}

#define enumval_def_os( _len_, _val_, _str_ )				\
    { _str_, 		{ .os = { .data = (unsigned char *)_val_, .len = _len_ }}}


static int dict_s6c_load_defs(char * conffile)
{
   TRACE_ENTRY("%p", conffile);
	struct dict_object * app_id16777312;

	/* Application Section */
	{
	  {
			struct dict_object * vendor;
			CHECK_dict_search(DICT_VENDOR, VENDOR_BY_NAME, "3GPP", &vendor)
			struct dict_application_data data = { 16777312, "S6c" };
			CHECK_dict_new( DICT_APPLICATION, &data, vendor, &app_id16777312)
	  }
	  /* Result codes */
	  {
			struct dict_object *type;
			CHECK_dict_search(DICT_TYPE, TYPE_BY_NAME, "Enumerated(Result-Code)",&type);
			struct dict_enumval_data        t_1 = { "General", { .u32=1 }};
			struct dict_enumval_data        t_2 = { "Permanent_Failures", { .u32=3 }};
			struct dict_enumval_data        t_3 = { "Transient_Failures", { .u32=4 }};

			CHECK_dict_new( DICT_ENUMVAL, &t_1, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_2, type, NULL);
			CHECK_dict_new( DICT_ENUMVAL, &t_3, type, NULL);

	  }
	}


   /* AVP section */
   {
		struct dict_object * Address_type;
		struct dict_object * UTF8String_type;
		struct dict_object * DiameterIdentity_type;
		struct dict_object * DiameterURI_type;
		struct dict_object * Time_type;
		struct dict_object * IPFilterRule_type;

		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Address", &Address_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "UTF8String", &UTF8String_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterIdentity", &DiameterIdentity_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "DiameterURI", &DiameterURI_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "Time", &Time_type);
		CHECK_dict_search( DICT_TYPE, TYPE_BY_NAME, "IPFilterRule", &IPFilterRule_type);

	
   }

   /* Commands section */
   {
		/* Send-Routing-Info-for-SM-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				8388647,	/* Code */
				"Send-Routing-Info-for-SM-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777312, &cmd)
		}
		/* Send-Routing-Info-for-SM-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				8388647,	/* Code */
				"Send-Routing-Info-for-SM-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777312, &cmd)
		}
		/* Alert-Service-Centre-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				8388648,	/* Code */
				"Alert-Service-Centre-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777312, &cmd)
		}
		/* Alert-Service-Centre-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				8388648,	/* Code */
				"Alert-Service-Centre-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777312, &cmd)
		}
		/* Report-SM-Delivery-Status-Request */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				8388649,	/* Code */
				"Report-SM-Delivery-Status-Request",	/* Name */
				CMD_FLAG_REQUEST | CMD_FLAG_ERROR,	/* Fixed flags */
				CMD_FLAG_REQUEST | CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777312, &cmd)
		}
		/* Report-SM-Delivery-Status-Answer */
		{
			struct dict_object* cmd;
			struct dict_cmd_data data = {
				8388649,	/* Code */
				"Report-SM-Delivery-Status-Answer",	/* Name */
				CMD_FLAG_REQUEST,	/* Fixed flags */
				CMD_FLAG_PROXIABLE,	/* Fixed flag values */
			};

			CHECK_dict_new( DICT_COMMAND, &data , app_id16777312, &cmd)
		}

   }

   return 0;
}

static int dict_s6c_load_rules(char * conffile)
{
   /* Grouped AVP section */
   {

   }	

   /* Commands section */
   {
	  /* Send-Routing-Info-for-SM-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Send-Routing-Info-for-SM-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Vendor-Specific-Application-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Session-State"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "MSISDN"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SMSMI-Correlation-ID"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SC-Address"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SM-RP-MTI"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SM-RP-SMEA"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SRR-Flags"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SM-Delivery-Not-Intended"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Send-Routing-Info-for-SM-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Send-Routing-Info-for-SM-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Vendor-Specific-Application-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Experimental-Result"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Session-State"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "User-Name"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Serving-Node"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Additional-Serving-Node"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "LMSI"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-Identifier"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "MWD-Status"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "MME-Absent-User-Diagnostic-SM"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "MSC-Absent-User-Diagnostic-SM"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SGSN-Absent-User-Diagnostic-SM"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Failed-AVP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Alert-Service-Centre-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Alert-Service-Centre-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Vendor-Specific-Application-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Session-State"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SC-Address"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-Identifier"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SMSMI-Correlation-ID"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Maximum-UE-Availability-Time"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SMS-GMSC-Alert-Event"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Serving-Node"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Alert-Service-Centre-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Alert-Service-Centre-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Vendor-Specific-Application-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Experimental-Result"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Session-State"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Failed-AVP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Report-SM-Delivery-Status-Request */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Report-SM-Delivery-Status-Request", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Vendor-Specific-Application-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Session-State"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Host"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Destination-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-Identifier"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SMSMI-Correlation-ID"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SC-Address"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "SM-Delivery-Outcome"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "RDR-Flags"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }
	  /* Report-SM-Delivery-Status-Answer */
	  {
		struct dict_object* cmd;
		CHECK_dict_search( DICT_COMMAND, CMD_BY_NAME, "Report-SM-Delivery-Status-Answer", &cmd)
		struct local_rules_definition rules[] =
		{
			{ { .avp_vendor = 0, .avp_name = "Session-Id"}, RULE_FIXED_HEAD, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "DRMP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Vendor-Specific-Application-Id"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Result-Code"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Experimental-Result"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Auth-Session-State"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Host"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Origin-Realm"}, RULE_REQUIRED, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "Supported-Features"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 10415, .avp_name = "User-Identifier"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Failed-AVP"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Proxy-Info"}, RULE_OPTIONAL, -1, -1 },
			{ { .avp_vendor = 0, .avp_name = "Route-Record"}, RULE_OPTIONAL, -1, -1 }
		};
		PARSE_loc_rules(rules, cmd);
	  }

   }

   LOG_D( "Extension 'Dictionary definitions for S6c (e10)' initialized");
   return 0;
}

int dict_entry(char * conffile)
{
	dict_s6c_load_defs(conffile);
	return dict_s6c_load_rules(conffile);
}

const char* dict_s6c_proto_ver(char * conffile) {
	return s6c_proto_ver;
}

const double dict_s6c_gen_ts(char * conffile) {
	return s6c_gen_date;
}

EXTENSION_ENTRY2("dict_s6c", dict_s6c_load_defs, dict_s6c_load_rules, "dict_ts29338_avps", "dict_ts29272_avps", "dict_ts29336_avps", "dict_ts29173_avps", "dict_ts29329_avps", "dict_ts29229_avps", "dict_rfc7944_avps");



