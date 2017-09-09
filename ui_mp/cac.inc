		#define CAC_THING_1 \
				if(!(tablelookup("mp/attachmentTable.csv",4,GPD_WS,0,"attachment",0),12)!=""|| \
				tablelookup("mp/attachmentTable.csv",4,GPD_WS,1,"attachment",0),12)!="")&& \
				(GPD_SHORT,"perks",0)=="specialty_null_gl"|| \
				GPD_SHORT,"perks",0)=="specialty_null_grip"|| \
				GPD_SHORT,"perks",0)=="specialty_null_shotgun")|| \
				GPD_SHORT,"perks",0)=="specialty_null_heartbeat") \
				{ \
					setPlayerData("customClasses",LOCALVARINT1,"perks",0,"specialty_null"); \
				}

		#define CAC_THING_2 \
				setLocalVarString "loadoutPrimary" 					(GPD_WS,0,"weapon")); \
				setLocalVarString "loadoutPrimaryAttachment" 		(GPD_WS,0,"attachment",0)); \
				setLocalVarString "loadoutPrimaryAttachment2" 		(GPD_WS,0,"attachment",1));

		#define CAC_THING_2_1 \
				if ( localVarString( "loadoutPrimaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutPrimaryAttachment2" ( "none" ); \
				}

		#define CAC_THING_3 \
				setLocalVarString "loadoutPrimaryCamo" 				(GPD_WS,0,"camo")); \
				setLocalVarString "loadoutSecondaryCamo" 			(GPD_WS,1,"camo")); \
				setLocalVarString "loadoutSecondary" 				(GPD_WS,1,"weapon")); \
				setLocalVarString "loadoutSecondaryAttachment" 		(GPD_WS,1,"attachment",0)); \
				setLocalVarString "loadoutSecondaryAttachment2" 	(GPD_WS,1,"attachment",1));

		#define CAC_THING_3_1 \
				if ( localvarstring( "loadoutSecondaryAttachment2" ) == "" ) \
				{ \
					setLocalVarString "loadoutSecondaryAttachment2" ( "none" ); \
				}

		#define CAC_THING_4 \
				setLocalVarString "loadoutSecondaryCamo" 			(GPD_WS,1,"camo")); \
				setLocalVarString "loadoutEquipment" 				(GPD_SHORT,"perks",0)); \
				setLocalVarString "loadoutPerk1" 					(GPD_SHORT,"perks",1)); \
				setLocalVarString "loadoutPerk2" 					(GPD_SHORT,"perks",2)); \
				setLocalVarString "loadoutPerk3" 					(GPD_SHORT,"perks",3)); \
				setLocalVarString "loadoutStreak1" 					(GPD_SHORTER("killstreaks",0)); \
				setLocalVarString "loadoutStreak2" 					(GPD_SHORTER("killstreaks",1)); \
				setLocalVarString "loadoutStreak3" 					(GPD_SHORTER("killstreaks",2)); \
				setLocalVarString "loadoutDeathStreak" 				(GPD_SHORT,"perks",4)); \
				setLocalVarString "loadoutOffhandSecondary" 		(GPD_SHORT,"specialGrenade")); \
				setLocalVarString "loadoutClassName" 				(GPD_SHORT,"name"));

		#define LOCALVARINT1 \
				localVarInt( "classIndex" )

		#define GPD_WS \
				getPlayerData("customClasses",LOCALVARINT1,"weaponSetups"

		#define GPD_SHORT \
				getPlayerData("customClasses",LOCALVARINT1

		#define GPD_SHORTER \
				getPlayerData

		#define CAC_THING_FOCUS \
				CAC_THING_1 	\
				CAC_THING_2 	\
				CAC_THING_2_1 	\
				CAC_THING_3 	\
				CAC_THING_3_1 	\
				CAC_THING_4

		#define PREPROC_CAC_CLOSEALL \
				close "popup_cac_weapon_primary"; \
				close "popup_primary_attachments"; \
				close "popup_secondary_attachments"  \
				close "popup_cac_weapon_secondary"; \
				close "popup_cac_handgun_secondary"; \
				close "popup_cac_machinePistols_secondary"; \
				close "popup_cac_assault_primary"; \
				close "popup_cac_SMG_primary"; \
				close "popup_cac_LMG_primary"; \
				close "popup_cac_sniper_primary"; \
				close "popup_cac_shotgun_primary"; \
				close "popup_cac_assault_secondary"; \
				close "popup_cac_SMG_secondary"; \
				close "popup_cac_sniper_secondary"; \
				close "popup_cac_shotgun_secondary"; \
				close "popup_cac_template"; \
				close "popup_cac_primary_camo"; \
				close "popup_cac_secondary_camo"; \
				close "popup_cac_bling"; \
				close "popup_cac_perk2"; \
				close "popup_cac_rocket_secondary"; \
				close "popup_primary_attachments_bling"; \
				close "popup_secondary_attachments_bling"; \
				close "popup_cac_other_primary"; \

// CREATE A CLASS POPUP -- 15 CLASSES /* will need to revise this. (cac_popup.menu) */
		#define CAC_STATNUM( statNum ) \
				setPlayerData("customClasses",statNum,"inUse","true"); \
				setlocalVarInt "classIndex" (statNum); \
				open "menu_cac_assault"; \

		#define CAC_STATNUM_HI(statNum) \
				CAC_THING_FOCUS \
				setlocalVarInt "classIndex" (statNum); \

		#define CAC_STATNUM_NAME( statNum ) \
				getPlayerData("customClasses",statNum,"name") \

		#define WHEN \
				when ( getPlayerData( "prestige" ) \

		#define LOCAL_WPN_ACTION1( statNum ) \

		#define DEF_1 \
				getPlayerData("customClasses",localVarInt("classIndex"),"weaponSetups",0,"weapon") \

		#define LOCAL_WEAPON_NAME( statNum ) \
				"@"+tablelookup("mp/attachmentTable.csv",statNum,tablelookup("mp/statsTable.csv",statNum,DEF_1,11),3) \

		#define LOCAL_WEAPON( itemIndex, statNum ) \
				CHOICE_BUTTON_FOCUS( itemIndex, LOCAL_WEAPON_NAME ( statNum ), LOCAL_WPN_ACTION1( statNum ), onFocusArg, leaveFocusArg ) \

// CREATE A CLASS WEAPONS PRIMARY - SECONDARY - EQUIPMENT - EXTRA - PERK 1/2/3 - DEATHSTREAK

		#define LOCAL_RIOT_ACTION( cacTypeStat ) \
				LOCAL_CAC_WEAPON_TYPE( REF_IS_PRIMARY, cacTypeStat ) \
				LOCAL_CACSETVARSTRINGS \
				LOCAL_CAC_WEAPON_ATTACHMENT_TYPE( REF_IS_PRIMARY, cacTypeStat ) \

		#define LOCAL_OFFHAND_FOCUS( cacTypeStat ) \
				setLocalVarString "ui_info_name" ("@"+tablelookup("mp/statsTable.csv",4,cacTypeStat,3)); \
				setLocalVarString "ui_info_desc" ("@"+tablelookup("mp/statstable.csv",4,cacTypeStat,7)); \
				setLocalVarString "ui_info_icon" (tablelookup("mp/statsTable.csv",4,cacTypeStat,6))

		#define LOCAL_RIOT_ITEM( itemIndex, textArg, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, textArg, LOCAL_RIOT_ACTION( cacTypeStat ), LOCAL_OFFHAND_FOCUS( cacTypeStat ), ; )

// extra
		#define LOCAL_EXTRA_ACTION( cacTypeStat ) \
				play "mouse_click"; \
				setPlayerData("customClasses","localVarInt"("classIndex"),"specialGrenade",cacTypeStat); \
				LOCAL_CACSETVARSTRINGS \
				close "popup_cac_extra"; \

		#define LOCAL_EXTRA_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, locstring("@MPUI_N_XN","@"+tablelookup("mp/statsTable.csv",4,cacTypeStat,3),int(tablelookup("mp/statsTable.csv",4,cacTypeStat,5))), LOCAL_EXTRA_ACTION( cacTypeStat ), LOCAL_OFFHAND_FOCUS( cacTypeStat ), ; ) \
				CHOICE_NEWICON_VIS( itemIndex, when ( weaponclassnew( cacTypeStat ) ) )
// equipment
		#define LOCAL_EQUIPMENT_ACTION( cacTypeStat ) \
				play "mouse_click"; \
				setPlayerData("perkNew",cacTypeStat,"false"); \
				if ( cacTypeStat != "specialty_bling" ) \
				{ \
					close "self"; \
				} \
				if ( 0 == 1 && cacTypeStat != "specialty_bling" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
				} \
				if ( 0 == 1 && cacTypeStat == "specialty_onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "onemanarmy" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "none" ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
					LOCAL_CACSETVARSTRINGS \
				} \
				if ( 0 == 1 && cacTypeStat != "specialty_onemanarmy" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) == "onemanarmy" ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "weapon" , "glock" ); \
					LOCAL_CACSETVARSTRINGS \
				} \
				if ( 0 == 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 4 , cacTypeStat ); \
				} \
				if ( 0 != 4 ) \
				{ \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "perks" , 0 , cacTypeStat ); \
				} \
				LOCAL_CACSETVARSTRINGS \
				close "popup_cac_equipment"; \

		#define LOCAL_EQUIPMENT_NOFOCUS( cacTypeStat ) \
				setPlayerData("perkNew",cacTypeStat,"false"); \
				setLocalVarString "ui_upgrade_ref" (tablelookup("mp/perkTable.csv",1,cacTypeStat,8)); \
				setPlayerData("perkNew","localVarString"("ui_upgrade_ref"),"false"); \

		#define LOCAL_EQUIPMENT_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,cacTypeStat,2), LOCAL_EQUIPMENT_ACTION( cacTypeStat ), \
				LOCAL_TYPE_FOCUS( cacTypeStat, \
				setLocalVarString "ui_selected_ref" ( cacTypeStat );, \
				setLocalVarString "ui_upgrade_ref" (tablelookup("mp/perkTable.csv",1,cacTypeStat,8));, \
				setLocalVarString "ui_challenge_ref" (tablelookup("mp/unlockTable.csv",0,localvarstring("ui_upgrade_ref"),3));, ; ) \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE \, LOCAL_EQUIPMENT_NOFOCUS( cacTypeStat ), when ( isitemunlocked( cacTypeStat ) ), disabled when ( !isitemunlocked( cacTypeStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when((getplayerdata("perkNew",cacTypeStat)||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,cacTypeStat,8))))) \
				CHOICE_LOCKEDICON_VIS( itemIndex,  when ( !isitemunlocked( cacTypeStat ) ) ) \

	// perk buttons

		#define LOCAL_PERK_NOFOCUS( cacTypeStat ) \
				setPlayerData("perkNew",cacTypeStat,"false"); \
				setLocalVarString "ui_upgrade_ref" (tablelookup("mp/perkTable.csv",1,cacTypeStat,8)); \
				setPlayerData("perkNew","localVarString"("ui_upgrade_ref"),"false"); \

		#define LOCAL_PERK1_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_EX( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,cacTypeStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,cacTypeStat,8))*(9-2)))), \
				setPlayerData( "perkNew" , cacTypeStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , cacTypeStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				LOCAL_IS_PERK_STAT( REF_PERK1, cacTypeStat ) \
				LOCAL_CACSETVARSTRINGS, LOCAL_TYPE_FOCUS( cacTypeStat, setLocalVarString "ui_selected_ref" ( cacTypeStat );, \
				setLocalVarString "ui_upgrade_ref" (tablelookup("mp/perkTable.csv",1,cacTypeStat,8));, \
				setLocalVarString "ui_challenge_ref" (tablelookup("mp/unlockTable.csv",0,localvarstring("ui_upgrade_ref"),4));, ; ) \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE, LOCAL_PERK_NOFOCUS( cacTypeStat ), disabled when ( !isitemunlocked( cacTypeStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when ((getplayerdata("perkNew",cacTypeStat)||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,cacTypeStat,8))))) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( !isitemunlocked( cacTypeStat ) ) ) \	

		#define LOCAL_PERK2_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_EX( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,cacTypeStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,cacTypeStat,8))*(9-2)))), \
				setPlayerData( "perkNew" , cacTypeStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , cacTypeStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				LOCAL_IS_PERK_STAT( REF_PERK2, cacTypeStat ) \
				LOCAL_CACSETVARSTRINGS , LOCAL_TYPE_FOCUS( cacTypeStat, setLocalVarString "ui_selected_ref" ( cacTypeStat );, \
				setLocalVarString "ui_upgrade_ref" (tablelookup("mp/perkTable.csv",1,cacTypeStat,8));, \
				setLocalVarString "ui_challenge_ref" (tablelookup("mp/unlockTable.csv",0,localvarstring("ui_upgrade_ref"),4));, ; ) \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE, LOCAL_PERK_NOFOCUS( cacTypeStat ), disabled when ( !isitemunlocked( cacTypeStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when ((getplayerdata("perkNew",cacTypeStat)||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,cacTypeStat,8))))) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( !isitemunlocked( cacTypeStat ) ) ) \	

		#define LOCAL_PERK3_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_EX( itemIndex, "@"+tablelookup("mp/perkTable.csv",1,cacTypeStat,int(2+(isitemunlocked(tablelookup("mp/perkTable.csv",1,cacTypeStat,8))*(9-2)))),\
				setPlayerData( "perkNew" , cacTypeStat , "false" ); \
				setLocalVarString "ui_upgrade_ref" ( tablelookup( "mp/perkTable.csv" , 1 , cacTypeStat , 8 ) ); \
				setPlayerData( "perkNew" , "localVarString" ( "ui_upgrade_ref" ) , "false" ); \
				LOCAL_IS_PERK_STAT( REF_PERK3, cacTypeStat ) \
				LOCAL_CACSETVARSTRINGS, LOCAL_TYPE_FOCUS( cacTypeStat, setLocalVarString "ui_selected_ref" ( cacTypeStat );, \
				setLocalVarString "ui_upgrade_ref" (tablelookup("mp/perkTable.csv",1,cacTypeStat,8));, \
				setLocalVarString "ui_challenge_ref" (tablelookup("mp/unlockTable.csv",0,localvarstring("ui_upgrade_ref"),4));, ; ) \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE, LOCAL_PERK_NOFOCUS( cacTypeStat ), disabled when ( !isitemunlocked( cacTypeStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when ((getplayerdata("perkNew",cacTypeStat)||getplayerdata("perkNew",tablelookup("mp/perkTable.csv",1,cacTypeStat,8))))) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( !isitemunlocked( cacTypeStat ) ) ) \	

		#define LOCAL_DEATHSTREAK_ACTION( cacTypeStat ) \
				setPlayerData( "perkNew" , cacTypeStat , "false" ); \
				LOCAL_IS_PERK_STAT( REF_DEATHSTREAK, cacTypeStat ) \
				LOCAL_CACSETVARSTRINGS \
	
		#define LOCAL_DEATHSTREAK_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_EX( itemIndex,"@"+tablelookup("mp/perkTable.csv",1,cacTypeStat,2), LOCAL_DEATHSTREAK_ACTION( cacTypeStat ), \
				LOCAL_TYPE_FOCUS( cacTypeStat, setLocalVarString "ui_selected_ref" ( cacTypeStat );, \
				setLocalVarString "ui_upgrade_ref" (tablelookup("mp/perkTable.csv",1,cacTypeStat,8));, \
				setLocalVarString "ui_challenge_ref" (tablelookup("mp/unlockTable.csv",0,localvarstring("ui_upgrade_ref"),3));, ; ) \
				setLocalVarString "ui_challenge_state" ( 1 ); \
				LOCAL_CH_STATE \, LOCAL_PERK_NOFOCUS( cacTypeStat ), disabled when ( !isitemunlocked( cacTypeStat ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when ( ( getplayerdata( "perkNew" , cacTypeStat ) || getplayerdata( "perkNew" , tablelookup( "mp/perkTable.csv" , 1 , cacTypeStat , 8 ) ) ) )) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( !isitemunlocked( cacTypeStat ) ) ) \
	
	// PRIMARY WEAPONS
		#define LOCAL_WEAPON_ACTION( cacTypeStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/statsTable.csv" , 4 , cacTypeStat , 3 ) ) \
				LOCAL_CAC_WEAPON_TYPE( REF_IS_PRIMARY, cacTypeStat ) \
				LOCAL_CACSETVARSTRINGS \
				LOCAL_CAC_WEAPON_ATTACHMENT_TYPE( REF_IS_PRIMARY, cacTypeStat ) \

		#define LOCAL_WEAPON_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, "@"+tablelookup("mp/statsTable.csv",4,cacTypeStat,3), LOCAL_WEAPON_ACTION( cacTypeStat ), setLocalVarString "ui_selected_ref" ( cacTypeStat );, setPlayerData( "weaponNew" , cacTypeStat , "false" );, when ( isitemunlocked( cacTypeStat ) ), disabled when ( !isitemunlocked( cacTypeStat ) ) ) \
				CHOICE_CAPTION_VIS( itemIndex, "@"+tablelookup("mp/statsTable.csv",4,cacTypeStat,3), when ( ( isitemunlocked( cacTypeStat ) == 0 ) ) ) \
				CHOICE_NEWICON_VIS( itemIndex, when((getplayerdata("weaponNew",cacTypeStat)||getplayerdataanybooltrue("camoNew",cacTypeStat)||getplayerdataanybooltrue("attachmentNew",cacTypeStat)))) \
				CHOICE_LOCKEDICON_VIS( itemIndex, when ( ( isitemunlocked( cacTypeStat ) == 0 ) ) ) \

		#define LOCAL_WEAPON2_ACTION( cacTypeStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/statsTable.csv" , 4 , cacTypeStat , 3 ) ) \
				LOCAL_CAC_WEAPON_TYPE( REF_IS_SECONDARY, cacTypeStat ) \
				LOCAL_CACSETVARSTRINGS \
				LOCAL_CAC_WEAPON_ATTACHMENT_TYPE( REF_IS_SECONDARY, cacTypeStat ) \

		#define LOCAL_WEAPON2_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_VIS( itemIndex, "@"+tablelookup("mp/statsTable.csv",4,cacTypeStat,3), LOCAL_WEAPON2_ACTION( cacTypeStat ), setLocalVarString "ui_selected_ref" ( cacTypeStat );, setPlayerData( "weaponNew" , cacTypeStat , "false" );, when ( isitemunlocked( cacTypeStat ) ) ) \

// CAMOS
		#define LOCAL_CAMO_ACTION( cacTypeStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/camoTable.csv" , 1 , cacTypeStat , 2 ) ) \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setPlayerData( "camoNew" , "localVarString" ( "tempName" ) , cacTypeStat , "false" ); \
				setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 0 , "camo" , cacTypeStat ); \
				LOCAL_CACSETVARSTRINGS \
				PREPROC_CAC_CLOSEALL \

		#define LOCAL_CAMO_NOFOCUS( cacTypeStat ) \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				setPlayerData( "camoNew" , "localVarString" ( "tempName" ) , cacTypeStat , "false" ); \

		#define LOCAL_WEAPON_CAMO( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS( itemIndex, "@"+tablelookup("mp/camoTable.csv",1,cacTypeStat,2), LOCAL_CAMO_ACTION( cacTypeStat ), \
				LOCAL_TYPE_FOCUS( cacTypeStat, setLocalVarString "ui_selected_ref" ( cacTypeStat );, \
				setLocalVarString "ui_weapon_ref"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"));, \
				setLocalVarString "ui_unlock_ref"(localvarstring("ui_weapon_ref")+" "+cacTypeStat);, \
				setLocalVarString "ui_challenge_ref"(tablelookup("mp/unlockTable.csv",0,localvarstring("ui_unlock_ref"),3)); ) \
				setLocalVarInt "ui_challenge_state" ( 1 ); \
				LOCAL_CH_REF( "ch_expert_" ) \, LOCAL_CAMO_NOFOCUS( cacTypeStat ) ) \

// ATTACHMENTS
		#define LOCAL_ATTACHMENT_NAME( cacTypeStat ) \
				"@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat),3) \

		#define LOCAL_ATTACHMENT_ACTION( cacTypeStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/attachmentTable.csv" , 4 , tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) , 11 ) , 3 ) ) \
				setLocalVarString "tempName"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
				setPlayerData("attachmentNew","localVarString"("tempName"),"localVarString"("ui_selected_ref"),"false");; \
				if(menuisopen("popup_primary_attachments_bling")||menuisopen("popup_secondary_attachments_bling")) \
				{ \
					setLocalVarString "tempName"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat)); \
					if((localvarstring("ui_attachment1")==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat)||localvarstring("ui_attachment2")==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat))) \
					{ \
						setLocalVarInt "tempInt"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat)); \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment","localVarInt"("tempInt"),"none"); \
					} \
					else \
					{ \
						setLocalVarInt "tempInt"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0)!="none"); \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment","localVarInt"("tempInt"),"localVarString"("tempName")); \
					} \
					setLocalVarString "ui_attachment1"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0)); \
					setLocalVarString "ui_attachment2"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)); \
					setLocalVarInt "ui_numAttachments"(0); \
					if(localvarstring("ui_attachment1")!="none") \
					{ \
						setLocalVarInt "ui_numAttachments"(localvarint("ui_numAttachments")+1); \
					} \
					if(localvarstring("ui_attachment2")!="none") \
					{ \
						setLocalVarInt "ui_numAttachments"(localvarint("ui_numAttachments")+1); \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \
				else \
				{ \
					if(getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling") \
					{ \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",1,"none");; \
					} \
					if(getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling"&&getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",1)==tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat)) \
					{ \
						setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",1,"none");; \
					} \
					setLocalVarString "tempName"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat)); \
					setPlayerData("customClasses","localVarInt"("classIndex"),"weaponSetups",0,"attachment",0,"localVarString"("tempName")); \
					if(0==0) \
					{ \
						open "popup_cac_primary_camo"; \
					} \
					else \
					{ \
						PREPROC_CAC_CLOSEALL \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \

		#define LOCAL_ATTACHMENT_NOFOCUS \
				setLocalVarString "tempName"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")); \
				if(localvarstring("ui_selected_ref")!="") \
				{ \
					setPlayerData("attachmentNew","localVarString"("tempName"),"localVarString"("ui_selected_ref"),"false");; \
				} \

		#define LOCAL_ATTACHMENT_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, LOCAL_ATTACHMENT_NAME( cacTypeStat ), LOCAL_ATTACHMENT_ACTION( cacTypeStat ), \
				LOCAL_TYPE_FOCUS( cacTypeStat, \
				setLocalVarString "ui_selected_ref"(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",REF_IS_PRIMARY,"weapon"),cacTypeStat));, \
				setLocalVarString "ui_weapon_ref"(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"));, \
				setLocalVarString "ui_unlock_ref"(localvarstring("ui_weapon_ref")+""+tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat));, \
				setLocalVarString "ui_challenge_ref"(tablelookup("mp/unlockTable.csv",0,localvarstring("ui_unlock_ref"),3)); ) \
				setLocalVarInt "ui_challenge_state"(1); LOCAL_CH_REF( "ch_marksman_" ) \, LOCAL_ATTACHMENT_NOFOCUS, \
				when(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat)!=""), \
				disabled when(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat)!="" \
				&&(!isitemunlocked(getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon")+"" \
				+(tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat))) \
				||((((getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling")&&menuisopen("popup_primary_attachments_bling"))||((getplayerdata("customClasses",localvarint("classIndex"),"perks",1)=="specialty_bling" \
				&&isitemunlocked("specialty_secondarybling"))&&menuisopen("popup_secondary_attachments_bling"))) \
				&&tablelookup("mp/attachmentCombos.csv",0,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"attachment",0),tablegetrownum("mp/attachmentCombos.csv",0,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",0,"weapon"),cacTypeStat)))=="no"))) ) \

		#define LOCAL_ATTACHMENT_BLING_NAME( cacTypeStat ) \
				"@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,localvarstring("loadoutPrimary"),cacTypeStat),3)

		#define LOCAL_ATTACHMENT_BLING_ACTION( cacTypeStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/attachmentTable.csv" , 4 , tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) , 3 ) ) \
				LOCAL_CAC_WEAPON_ATTACHMENT_ACTION1( REF_IS_PRIMARY, cacTypeStat ) \

		#define LOCAL_ATTACHMENT_BLING_FOCUS( cacTypeStat ) \
				LOCAL_TYPE_FOCUS( cacTypeStat, \
				setLocalVarString "ui_selected_ref" ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) );, \
				setLocalVarString "ui_weapon_ref" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) );, \
				setLocalVarString "ui_unlock_ref" ( localvarstring( "ui_weapon_ref" ) + " " + tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) );, \
				setLocalVarString "ui_challenge_ref" ( tablelookup( "mp/unlockTable.csv" , 0 , localvarstring( "ui_unlock_ref" ) , 3 ) ); ) \
				setLocalVarInt "ui_challenge_state" ( 1 ); \
				LOCAL_CH_REF( "ch_marksman_" ) \
				LOCAL_CAC_WEAPON_ATTACHMENT_ACTION4_EXTRA( cacTypeStat ) \

		#define LOCAL_ATTACHMENT_BLING_NOFOCUS \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "weapon" ) ); \
				if ( localvarstring( "ui_selected_ref" ) != "" ) \
				{ \
					setPlayerData( "attachmentNew" , "localVarString" ( "tempName" ) , "localVarString" ( "ui_selected_ref" ) , "false" ); \
				} \

		#define LOCAL_ATTACHMENT_BLING_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_VIS_EX( itemIndex, LOCAL_ATTACHMENT_BLING_NAME( cacTypeStat ), LOCAL_ATTACHMENT_BLING_ACTION( cacTypeStat ), LOCAL_ATTACHMENT_BLING_FOCUS( cacTypeStat ), LOCAL_ATTACHMENT_BLING_NOFOCUS, \
				when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) != "" ), \
				disabled when ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) != "" \
				&& ( !isitemunlocked( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , REF_IS_PRIMARY , "weapon" ) + " " + ( tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) ) ) \
				|| ( !( localvarstring( "ui_attachment1" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) || localvarstring( "ui_attachment2" ) == tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) ) \
				&& ( ( !( tablelookup( "mp/attachmentCombos.csv" , 0 , tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) , tablegetrownum( "mp/attachmentCombos.csv" , 0 , localvarstring( "ui_attachment1" ) ) ) != "no" ) \
				|| !( tablelookup( "mp/attachmentCombos.csv" , 0 , tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) , tablegetrownum( "mp/attachmentCombos.csv" , 0 , localvarstring( "ui_attachment2" ) ) ) != "no" ) \
				|| localvarint( "ui_numAttachments" ) == 2 ) ) ) ) ) ) \
				PREPROC_SHADER_DRAW( CHOICE_RECT( itemIndex ), ORIGIN_NONE, "popup_button_selected_bar_bling", 0.8 0.6 0.1 1 \
				visible when ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 0 ) \
				== tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) || getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 0 , "attachment" , 1 ) \
				== tablelookup( "mp/statsTable.csv" , 4 , localvarstring( "loadoutPrimary" ) , cacTypeStat ) ) ) \

// SECONDARY ATTACHMENTS
// ATTACHMENTS
		#define LOCAL_ATTACHMENT2_NAME( cacTypeStat ) \
				"@"+tablelookup("mp/attachmentTable.csv",4,tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon"),cacTypeStat),3) \

		#define LOCAL_ATTACHMENT2_ACTION( cacTypeStat ) \
				UI_TABDEPTH2( ;, "@" + tablelookup( "mp/attachmentTable.csv" , 4 , tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , cacTypeStat ) , 3 ) ) \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				setPlayerData( "attachmentNew" , "localVarString" ( "tempName" ) , "localVarString" ( "ui_selected_ref" ) , "false" ) ;; \
				if ( menuisopen( "popup_primary_attachments_bling" ) || menuisopen( "popup_secondary_attachments_bling" ) ) \
				{ \
					setLocalVarString "tempName" ( tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , cacTypeStat ) ); \
					if ( ( localvarstring( "ui_attachment1" ) == tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , cacTypeStat ) || localvarstring( "ui_attachment2" ) == tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , cacTypeStat ) ) ) \
					{ \
						setLocalVarInt "tempInt" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) == tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , cacTypeStat ) ); \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , "localVarInt" ( "tempInt" ) , "none" ); \
					} \
					else \
					{ \
						setLocalVarInt "tempInt" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) != "none" ); \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , "localVarInt" ( "tempInt" ) , "localVarString" ( "tempName" ) ); \
					} \
					setLocalVarString "ui_attachment1" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 ) ); \
					setLocalVarString "ui_attachment2" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) ); \
					setLocalVarInt "ui_numAttachments" ( 0 ); \
					if ( localvarstring( "ui_attachment1" ) != "none" ) \
					{ \
						setLocalVarInt "ui_numAttachments" ( localvarint( "ui_numAttachments" ) + 1 ); \
					} \
					if ( localvarstring( "ui_attachment2" ) != "none" ) \
					{ \
						setLocalVarInt "ui_numAttachments" ( localvarint( "ui_numAttachments" ) + 1 ); \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \
				else \
				{ \
					if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
					} \
					if ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "perks" , 1 ) == "specialty_bling" && getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 ) == tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , cacTypeStat ) ) \
					{ \
						setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 1 , "none" ); \
					} \
					setLocalVarString "tempName" ( tablelookup( "mp/statsTable.csv" , 4 , getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) , cacTypeStat ) ); \
					setPlayerData( "customClasses" , "localVarInt" ( "classIndex" ) , "weaponSetups" , 1 , "attachment" , 0 , "localVarString" ( "tempName" ) ); \
					if ( 1 == 0 ) \
					{ \
						open "popup_cac_primary_camo"; \
					} \
					else \
					{ \
						PREPROC_CAC_CLOSEALL \
					} \
					LOCAL_CACSETVARSTRINGS \
				} \
			
		#define LOCAL_ATTACHMENT2_NOFOCUS \
				setLocalVarString "tempName" ( getplayerdata( "customClasses" , localvarint( "classIndex" ) , "weaponSetups" , 1 , "weapon" ) ); \
				if ( localvarstring( "ui_selected_ref" ) != "" ) \
				{ \
					setPlayerData( "attachmentNew" , "localVarString" ( "tempName" ) , "localVarString" ( "ui_selected_ref" ) , "false" ) ;; \
				} \

		#define LOCAL_ATTACHMENT2_ITEM( itemIndex, cacTypeStat ) \
				CHOICE_BUTTON_FOCUS_VIS( itemIndex, LOCAL_ATTACHMENT2_NAME( cacTypeStat ), LOCAL_ATTACHMENT2_ACTION( cacTypeStat ), \
				LOCAL_TYPE_FOCUS( cacTypeStat, \
				setLocalVarString "ui_selected_ref" (tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon"),cacTypeStat));, \
				setLocalVarString "ui_weapon_ref" (getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon"));, \
				setLocalVarString "ui_unlock_ref" (localvarstring("ui_weapon_ref")+" "+tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon"),cacTypeStat));, \
				setLocalVarString "ui_challenge_ref" (tablelookup("mp/unlockTable.csv",0,localvarstring("ui_unlock_ref"),3)); ) \
				setLocalVarInt "ui_challenge_state" ( 1 ); \
				LOCAL_CH_REF( "ch_marksman_" ), LOCAL_ATTACHMENT2_NOFOCUS, when (tablelookup("mp/statsTable.csv",4,getplayerdata("customClasses",localvarint("classIndex"),"weaponSetups",1,"weapon"),cacTypeStat)!=""))\