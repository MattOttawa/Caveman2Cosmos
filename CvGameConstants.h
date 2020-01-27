#pragma once

#ifndef CIV4_GAME_DEFINES_H
#define CIV4_GAME_DEFINES_H

class CvGameConstants
{
public:
	CvGameConstants();
	void cacheGlobalDefinesXML();

	void setANIMAL_SPAWN_MODIFIER(int iValue);
	int getANIMAL_SPAWN_MODIFIER() const;

	void setC2C_MIN_PROP_CONTROL(int iValue);
	int getC2C_MIN_PROP_CONTROL() const;

	void setCURSOR_SPLITH(int iValue);
	int getCURSOR_SPLITH() const;

	void setUSE_CANNOT_RESEARCH_CALLBACK(int iValue);
	int getUSE_CANNOT_RESEARCH_CALLBACK() const;

	void setMINIMUM_PLAYERS_WITH_TECH_FOR_AUTO_CORPORATION_FOUNDING(int iValue);
	int getMINIMUM_PLAYERS_WITH_TECH_FOR_AUTO_CORPORATION_FOUNDING() const;

	void setNUKE_UNIT_DAMAGE_BASE(int iValue);
	int getNUKE_UNIT_DAMAGE_BASE() const;

	void setRIVER_ATTACK_MODIFIER(int iValue);
	int getRIVER_ATTACK_MODIFIER() const;

	void setRIVER_EXTRA_MOVEMENT(int iValue);
	int getRIVER_EXTRA_MOVEMENT() const;

	void setBUG_HURRY_OVERFLOW_HOVER_INCLUDE_CURRENT(int iValue);
	int getBUG_HURRY_OVERFLOW_HOVER_INCLUDE_CURRENT() const;

	void setCORPORATION_FOUND_CHECK_TURNS(int iValue);
	int getCORPORATION_FOUND_CHECK_TURNS() const;

	void setBUG_CITYBAR_DRAFT_ANGER(int iValue);
	int getBUG_CITYBAR_DRAFT_ANGER() const;

	void setBUG_CITY_SCREEN_REMOVE_SPECIALIST_HOVER(int iValue);
	int getBUG_CITY_SCREEN_REMOVE_SPECIALIST_HOVER() const;

	void setMIN_CONVERSION_TURNS(int iValue);
	int getMIN_CONVERSION_TURNS() const;

	void setMIN_ANIMAL_STARTING_DISTANCE(int iValue);
	int getMIN_ANIMAL_STARTING_DISTANCE() const;

	void setRELIGION_REMOVAL_GOLD(int iValue);
	int getRELIGION_REMOVAL_GOLD() const;

	void setTECH_DIFFUSION_ENABLE(int iValue);
	int getTECH_DIFFUSION_ENABLE() const;

	void setUSE_ON_UNIT_SET_XY_CALLBACK(int iValue);
	int getUSE_ON_UNIT_SET_XY_CALLBACK() const;

	void setTEMP_HAPPY(int iValue);
	int getTEMP_HAPPY() const;

	void setACO_SHOW_SHIFT_INSTRUCTIONS(int iValue);
	int getACO_SHOW_SHIFT_INSTRUCTIONS() const;

	void setUSE_CANNOT_DO_CIVIC_CALLBACK(int iValue);
	int getUSE_CANNOT_DO_CIVIC_CALLBACK() const;

	void setUSE_CAN_DO_MELTDOWN_CALLBACK(int iValue);
	int getUSE_CAN_DO_MELTDOWN_CALLBACK() const;

	void setAI_CAN_DISBAND_UNITS(int iValue);
	int getAI_CAN_DISBAND_UNITS() const;

	void setPLOTS_PER_RIVER_EDGE(int iValue);
	int getPLOTS_PER_RIVER_EDGE() const;

	void setUNIT_VISIBILITY_RANGE(int iValue);
	int getUNIT_VISIBILITY_RANGE() const;

	void setPLOT_VISIBILITY_RANGE(int iValue);
	int getPLOT_VISIBILITY_RANGE() const;

	void setSHALLOW_WATER_TERRAIN(int iValue);
	int getSHALLOW_WATER_TERRAIN() const;

	void setSHOW_BUILDINGS_LEVEL(int iValue);
	int getSHOW_BUILDINGS_LEVEL() const;

	void setCAMERA_CITY_NO_PITCH(int iValue);
	int getCAMERA_CITY_NO_PITCH() const;

	void setCONSCRIPT_MIN_CULTURE_PERCENT(int iValue);
	int getCONSCRIPT_MIN_CULTURE_PERCENT() const;

	void setWE_LOVE_THE_KING_RAND(int iValue);
	int getWE_LOVE_THE_KING_RAND() const;

	void setACO_ENABLED(int iValue);
	int getACO_ENABLED() const;

	void setCURSOR_SIZENW(int iValue);
	int getCURSOR_SIZENW() const;

	void setNEW_CITY_BUILDING_VALUE_MODIFIER(int iValue);
	int getNEW_CITY_BUILDING_VALUE_MODIFIER() const;

	void setNPC1_LEADER(int iValue);
	int getNPC1_LEADER() const;

	void setSTART_YEAR(int iValue);
	int getSTART_YEAR() const;

	void setUSE_ON_UNIT_CREATED_CALLBACK(int iValue);
	int getUSE_ON_UNIT_CREATED_CALLBACK() const;

	void setBANDIT_SPAWN_MODIFIER(int iValue);
	int getBANDIT_SPAWN_MODIFIER() const;

	void setCURSOR_SPLITV(int iValue);
	int getCURSOR_SPLITV() const;

	void setNPC2_LEADER(int iValue);
	int getNPC2_LEADER() const;

	void setGOLDEN_AGE_UNITS_MULTIPLIER(int iValue);
	int getGOLDEN_AGE_UNITS_MULTIPLIER() const;

	void setNPC3_LEADER(int iValue);
	int getNPC3_LEADER() const;

	void setAI_HANDICAP(int iValue);
	int getAI_HANDICAP() const;

	void setNPC4_LEADER(int iValue);
	int getNPC4_LEADER() const;

	void setPAGE_IN_DIST_SYMBOLS(int iValue);
	int getPAGE_IN_DIST_SYMBOLS() const;

	void setCITY_DEFENSE_DAMAGE_HEAL_RATE(int iValue);
	int getCITY_DEFENSE_DAMAGE_HEAL_RATE() const;

	void setDEFAULT_FLEXIBLE_DIFFICULTY_TURN_INCREMENTS(int iValue);
	int getDEFAULT_FLEXIBLE_DIFFICULTY_TURN_INCREMENTS() const;

	void setNPC5_LEADER(int iValue);
	int getNPC5_LEADER() const;

	void setUSE_CAN_TRAIN_CALLBACK(int iValue);
	int getUSE_CAN_TRAIN_CALLBACK() const;

	void setNPC6_LEADER(int iValue);
	int getNPC6_LEADER() const;

	void setNPC7_LEADER(int iValue);
	int getNPC7_LEADER() const;

	void setNUM_UNIT_PREREQ_OR_BONUSES(int iValue);
	int getNUM_UNIT_PREREQ_OR_BONUSES() const;

	void setBASE_RELIGION_ANARCHY_LENGTH(int iValue);
	int getBASE_RELIGION_ANARCHY_LENGTH() const;

	void setFOREIGN_TRADE_MODIFIER(int iValue);
	int getFOREIGN_TRADE_MODIFIER() const;

	void setNPC8_LEADER(int iValue);
	int getNPC8_LEADER() const;

	void setPAGE_IN_DIST_FEATURES(int iValue);
	int getPAGE_IN_DIST_FEATURES() const;

	void setSPY_DESTROY_COST_MULTIPLIER(int iValue);
	int getSPY_DESTROY_COST_MULTIPLIER() const;

	void setCAN_TRADE_GOLD(int iValue);
	int getCAN_TRADE_GOLD() const;

	void setWAR_PRIZES(int iValue);
	int getWAR_PRIZES() const;

	void setCAN_TRADE_CORPORATIONS(int iValue);
	int getCAN_TRADE_CORPORATIONS() const;

	void setGW_MOD_ENABLED(int iValue);
	int getGW_MOD_ENABLED() const;

	void setLIMITED_RELIGIONS_EXCEPTIONS(int iValue);
	int getLIMITED_RELIGIONS_EXCEPTIONS() const;

	void setUNIT_MULTISELECT_MAX(int iValue);
	int getUNIT_MULTISELECT_MAX() const;

	void setWARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT(int iValue);
	int getWARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT() const;

	void setCAPITAL_TRADE_MODIFIER(int iValue);
	int getCAPITAL_TRADE_MODIFIER() const;

	void setCOMMERCE_PERCENT_CHANGE_INCREMENTS(int iValue);
	int getCOMMERCE_PERCENT_CHANGE_INCREMENTS() const;

	void setUSE_CAN_DO_PLOT_CULTURE_CALLBACK(int iValue);
	int getUSE_CAN_DO_PLOT_CULTURE_CALLBACK() const;

	void setINCREASING_DIFFICULTY_TURN_CHECK_INCREMENTS(int iValue);
	int getINCREASING_DIFFICULTY_TURN_CHECK_INCREMENTS() const;

	void setCITY_SCREEN_FOG_ENABLED(int iValue);
	int getCITY_SCREEN_FOG_ENABLED() const;

	void setGREAT_GENERALS_THRESHOLD_INCREASE(int iValue);
	int getGREAT_GENERALS_THRESHOLD_INCREASE() const;

	void setNUM_BUILDING_AND_TECH_PREREQS(int iValue);
	int getNUM_BUILDING_AND_TECH_PREREQS() const;

	void setTRADE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT(int iValue);
	int getTRADE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT() const;

	void setBUG_UNIT_EXPERIENCE_MODIFIERS_HOVER(int iValue);
	int getBUG_UNIT_EXPERIENCE_MODIFIERS_HOVER() const;

	void setUNIT_UPGRADE_COST_PER_PRODUCTION(int iValue);
	int getUNIT_UPGRADE_COST_PER_PRODUCTION() const;

	void setACO_SHOW_DEFENDER_HEALTH_BARS(int iValue);
	int getACO_SHOW_DEFENDER_HEALTH_BARS() const;

	void setBARREN_TERRAIN(int iValue);
	int getBARREN_TERRAIN() const;

	void setIDW_ENABLED(int iValue);
	int getIDW_ENABLED() const;

	void setTREAT_NEGATIVE_GOLD_AS_MAINTENANCE(int iValue);
	int getTREAT_NEGATIVE_GOLD_AS_MAINTENANCE() const;

	void setBUG_CITYBAR_HURRY_ANGER(int iValue);
	int getBUG_CITYBAR_HURRY_ANGER() const;

	void setCONSCRIPT_MIN_CITY_POPULATION(int iValue);
	int getCONSCRIPT_MIN_CITY_POPULATION() const;

	void setDEFY_RESOLUTION_ANGER_DIVISOR(int iValue);
	int getDEFY_RESOLUTION_ANGER_DIVISOR() const;

	void setCAN_TRADE_MAPS(int iValue);
	int getCAN_TRADE_MAPS() const;

	void setCORPORATION_RESOURCE_BASE_INFLUENCE(int iValue);
	int getCORPORATION_RESOURCE_BASE_INFLUENCE() const;

	void setACO_FORCE_ORIGINAL_ODDS(int iValue);
	int getACO_FORCE_ORIGINAL_ODDS() const;

	void setUSE_ON_UPDATE_CALLBACK(int iValue);
	int getUSE_ON_UPDATE_CALLBACK() const;

	void setVIEWPORT_FOCUS_BORDER(int iValue);
	int getVIEWPORT_FOCUS_BORDER() const;

	void setBUG_CITYBAR_SPECIALISTS(int iValue);
	int getBUG_CITYBAR_SPECIALISTS() const;

	void setEVENT_PROBABILITY_ROLL_SIDES(int iValue);
	int getEVENT_PROBABILITY_ROLL_SIDES() const;

	void setMAX_EVASION_PROBABILITY(int iValue);
	int getMAX_EVASION_PROBABILITY() const;

	void setMIN_REVOLUTION_TURNS(int iValue);
	int getMIN_REVOLUTION_TURNS() const;

	void setSCORE_HANDICAP_PERCENT_OFFSET(int iValue);
	int getSCORE_HANDICAP_PERCENT_OFFSET() const;

	void setUNIT_PRODUCTION_DECAY_PERCENT(int iValue);
	int getUNIT_PRODUCTION_DECAY_PERCENT() const;

	void setAMPHIB_ATTACK_MODIFIER(int iValue);
	int getAMPHIB_ATTACK_MODIFIER() const;

	void setESPIONAGE_SPENDING_MULTIPLIER(int iValue);
	int getESPIONAGE_SPENDING_MULTIPLIER() const;

	void setGREATER_COMMERCE_SWITCH_POINT(int iValue);
	int getGREATER_COMMERCE_SWITCH_POINT() const;

	void setBATTLEFIELD_PROMOTIONS(int iValue);
	int getBATTLEFIELD_PROMOTIONS() const;

	void setC2C_ROUGH_BOMBARD_VALUE_MODIFIER(int iValue);
	int getC2C_ROUGH_BOMBARD_VALUE_MODIFIER() const;

	void setADVANCED_START_CULTURE_COST(int iValue);
	int getADVANCED_START_CULTURE_COST() const;

	void setRELIGION_SPREAD_DISTANCE_DIVISOR(int iValue);
	int getRELIGION_SPREAD_DISTANCE_DIVISOR() const;

	void setROUTE_FEATURE_GROWTH_MODIFIER(int iValue);
	int getROUTE_FEATURE_GROWTH_MODIFIER() const;

	void setWE_LOVE_THE_KING_POPULATION_MIN_POPULATION(int iValue);
	int getWE_LOVE_THE_KING_POPULATION_MIN_POPULATION() const;

	void setBBAI_ATTACK_CITY_STACK_RATIO(int iValue);
	int getBBAI_ATTACK_CITY_STACK_RATIO() const;

	void setBBAI_DEFENSIVE_PACT_BEHAVIOR(int iValue);
	int getBBAI_DEFENSIVE_PACT_BEHAVIOR() const;

	void setCONSCRIPT_ANGER_DIVISOR(int iValue);
	int getCONSCRIPT_ANGER_DIVISOR() const;

	void setBASE_SPY_DESTROY_COST(int iValue);
	int getBASE_SPY_DESTROY_COST() const;

	void setBUG_BUILDING_ADDITIONAL_FOOD_HOVER(int iValue);
	int getBUG_BUILDING_ADDITIONAL_FOOD_HOVER() const;

	void setBUG_CITYBAR_HIDE_INSTRUCTIONS(int iValue);
	int getBUG_CITYBAR_HIDE_INSTRUCTIONS() const;

	void setCURSOR_AIRBOMB(int iValue);
	int getCURSOR_AIRBOMB() const;

	void setINQUISITION_BUILDING_GOLD_DIVISOR(int iValue);
	int getINQUISITION_BUILDING_GOLD_DIVISOR() const;

	void setWW_ATTACKED_WITH_NUKE(int iValue);
	int getWW_ATTACKED_WITH_NUKE() const;

	void setADVANCED_START_CITY_COST_INCREASE(int iValue);
	int getADVANCED_START_CITY_COST_INCREASE() const;

	void setBUILDING_PRODUCTION_DECAY_PERCENT(int iValue);
	int getBUILDING_PRODUCTION_DECAY_PERCENT() const;

	void setRIVAL_TEAM_STARTING_MODIFIER(int iValue);
	int getRIVAL_TEAM_STARTING_MODIFIER() const;

	void setBBAI_SKIP_BOMBARD_BASE_STACK_RATIO(int iValue);
	int getBBAI_SKIP_BOMBARD_BASE_STACK_RATIO() const;

	void setSTANDARD_HANDICAP_QUICK(int iValue);
	int getSTANDARD_HANDICAP_QUICK() const;

	void setBUG_BUILDING_ADDITIONAL_GREAT_PEOPLE_HOVER(int iValue);
	int getBUG_BUILDING_ADDITIONAL_GREAT_PEOPLE_HOVER() const;

	void setCAN_TRADE_CONTACT(int iValue);
	int getCAN_TRADE_CONTACT() const;

	void setCITY_HEAL_RATE(int iValue);
	int getCITY_HEAL_RATE() const;

	void setESPIONAGE_INTERCEPT_COUNTERESPIONAGE_MISSION(int iValue);
	int getESPIONAGE_INTERCEPT_COUNTERESPIONAGE_MISSION() const;

	void setUSE_CANNOT_CONSTRUCT_CALLBACK(int iValue);
	int getUSE_CANNOT_CONSTRUCT_CALLBACK() const;

	void setALWAYS_USE_MAX_COMPAT_SAVES(int iValue);
	int getALWAYS_USE_MAX_COMPAT_SAVES() const;

	void setBARBARIAN_LEADER(int iValue);
	int getBARBARIAN_LEADER() const;

	void setBUG_CITYBAR_BASE_VALUES(int iValue);
	int getBUG_CITYBAR_BASE_VALUES() const;

	void setUSE_ON_UNIT_SELECTED_CALLBACK(int iValue);
	int getUSE_ON_UNIT_SELECTED_CALLBACK() const;

	void setLAKE_PLOT_RAND(int iValue);
	int getLAKE_PLOT_RAND() const;

	void setNUM_LAKE_NAMES(int iValue);
	int getNUM_LAKE_NAMES() const;

	void setACO_SHOW_ATTACKER_HEALTH_BARS(int iValue);
	int getACO_SHOW_ATTACKER_HEALTH_BARS() const;

	void setACO_SHOW_DEFENDER_INFO(int iValue);
	int getACO_SHOW_DEFENDER_INFO() const;

	void setBATTLE_EFFECT_LESS_PRODUCTION(int iValue);
	int getBATTLE_EFFECT_LESS_PRODUCTION() const;

	void setFREE_TRADE_CORPORATION_SPREAD_MOD(int iValue);
	int getFREE_TRADE_CORPORATION_SPREAD_MOD() const;

	void setNUKE_POPULATION_DEATH_RAND_1(int iValue);
	int getNUKE_POPULATION_DEATH_RAND_1() const;

	void setNUKE_POPULATION_DEATH_RAND_2(int iValue);
	int getNUKE_POPULATION_DEATH_RAND_2() const;

	void setNO_ESPIONAGE_CULTURE_LEVEL_MODIFIER(int iValue);
	int getNO_ESPIONAGE_CULTURE_LEVEL_MODIFIER() const;

	void setBUG_SPECIALIST_HOVER_ACTUAL_EFFECTS(int iValue);
	int getBUG_SPECIALIST_HOVER_ACTUAL_EFFECTS() const;

	void setCORPORATION_SPREAD_RAND(int iValue);
	int getCORPORATION_SPREAD_RAND() const;

	void setCURSOR_DEFAULT(int iValue);
	int getCURSOR_DEFAULT() const;

	void setBUG_CITYBAR_STARVATION_TURNS(int iValue);
	int getBUG_CITYBAR_STARVATION_TURNS() const;

	void setCAN_TRADE_OPEN_BORDERS(int iValue);
	int getCAN_TRADE_OPEN_BORDERS() const;

	void setMAX_EXPERIENCE_AFTER_UPGRADE(int iValue);
	int getMAX_EXPERIENCE_AFTER_UPGRADE() const;

	void setNUM_PEAK_NAMES(int iValue);
	int getNUM_PEAK_NAMES() const;

	void setTEST_GAMEFONTS(int iValue);
	int getTEST_GAMEFONTS() const;

	void setACO_SHOW_UNHARMED_ODDS(int iValue);
	int getACO_SHOW_UNHARMED_ODDS() const;

	void setBUG_CITYBAR_FOOD_ASSIST(int iValue);
	int getBUG_CITYBAR_FOOD_ASSIST() const;

	void setCAN_TRADE_EMBARGO(int iValue);
	int getCAN_TRADE_EMBARGO() const;

	void setINITIAL_OUTSIDE_UNIT_GOLD_PERCENT(int iValue);
	int getINITIAL_OUTSIDE_UNIT_GOLD_PERCENT() const;

	void setSS_ASSASSINATE(int iValue);
	int getSS_ASSASSINATE() const;

	void setAIR_COMBAT_DAMAGE(int iValue);
	int getAIR_COMBAT_DAMAGE() const;

	void setDCM_RANGE_BOMBARD(int iValue);
	int getDCM_RANGE_BOMBARD() const;

	void setDCM_RB_CITY_INACCURACY(int iValue);
	int getDCM_RB_CITY_INACCURACY() const;

	void setBBAI_VICTORY_STRATEGY_CULTURE(int iValue);
	int getBBAI_VICTORY_STRATEGY_CULTURE() const;

	void setCAN_TRADE_CITIES(int iValue);
	int getCAN_TRADE_CITIES() const;

	void setCAN_TRADE_CIVICS(int iValue);
	int getCAN_TRADE_CIVICS() const;

	void setENABLE_DYNAMIC_UNIT_ENTITIES(int iValue);
	int getENABLE_DYNAMIC_UNIT_ENTITIES() const;

	void setMAX_DISTANCE_CITY_MAINTENANCE(int iValue);
	int getMAX_DISTANCE_CITY_MAINTENANCE() const;

	void setCURSOR_AIRLIFT(int iValue);
	int getCURSOR_AIRLIFT() const;

	void setDCM_STACK_ATTACK(int iValue);
	int getDCM_STACK_ATTACK() const;

	void setFROZEN_TERRAIN(int iValue);
	int getFROZEN_TERRAIN() const;

	void setMIN_CITY_RANGE(int iValue);
	int getMIN_CITY_RANGE() const;

	void setTEMPERATE_FEATURE(int iValue);
	int getTEMPERATE_FEATURE() const;

	void setROUTES_UPGRADE(int iValue);
	int getROUTES_UPGRADE() const;

	void setAI_SHOULDNT_MANAGE_PLOT_ASSIGNMENT(int iValue);
	int getAI_SHOULDNT_MANAGE_PLOT_ASSIGNMENT() const;

	void setFEATURE_GROWTH_MODIFIER(int iValue);
	int getFEATURE_GROWTH_MODIFIER() const;

	void setGREAT_PEOPLE_THRESHOLD(int iValue);
	int getGREAT_PEOPLE_THRESHOLD() const;

	void setINITIAL_CITY_POPULATION(int iValue);
	int getINITIAL_CITY_POPULATION() const;

	void setCIVILOPEDIA_SHOW_ACTIVE_CIVS_ONLY(int iValue);
	int getCIVILOPEDIA_SHOW_ACTIVE_CIVS_ONLY() const;

	void setESPIONAGE_INTERCEPT_RECENT_MISSION(int iValue);
	int getESPIONAGE_INTERCEPT_RECENT_MISSION() const;

	void setSUPER_FORTS_DURATION_BEFORE_REVOLT(int iValue);
	int getSUPER_FORTS_DURATION_BEFORE_REVOLT() const;

	void setBUG_CITYBAR_BUILDING_ACTUAL_EFFECTS(int iValue);
	int getBUG_CITYBAR_BUILDING_ACTUAL_EFFECTS() const;

	void setESPIONAGE_CITY_HOLY_CITY_MOD(int iValue);
	int getESPIONAGE_CITY_HOLY_CITY_MOD() const;

	void setVICTORY_SOUNDTRACK_AVAILABLE(int iValue);
	int getVICTORY_SOUNDTRACK_AVAILABLE() const;

	void setBARBARIAN_CIVILIZATION(int iValue);
	int getBARBARIAN_CIVILIZATION() const;

	void setBASE_UNIT_UPGRADE_COST(int iValue);
	int getBASE_UNIT_UPGRADE_COST() const;

	void setMAX_BUILDINGS_PER_CITY(int iValue);
	int getMAX_BUILDINGS_PER_CITY() const;

	void setBASE_SPY_SABOTAGE_COST(int iValue);
	int getBASE_SPY_SABOTAGE_COST() const;

	void setBBAI_SKIP_BOMBARD_BEST_ATTACK_ODDS(int iValue);
	int getBBAI_SKIP_BOMBARD_BEST_ATTACK_ODDS() const;

	void setBUG_PLOT_HOVER_PARTIAL_BUILDS(int iValue);
	int getBUG_PLOT_HOVER_PARTIAL_BUILDS() const;

	void setIDW_NO_NAVAL_INFLUENCE(int iValue);
	int getIDW_NO_NAVAL_INFLUENCE() const;

	void setINITIAL_BASE_FREE_UNITS(int iValue);
	int getINITIAL_BASE_FREE_UNITS() const;

	void setCURSOR_SIZEALL(int iValue);
	int getCURSOR_SIZEALL() const;

	void setGLOBAL_WARMING_TERRAIN(int iValue);
	int getGLOBAL_WARMING_TERRAIN() const;

	void setMAX_INTERCEPTION_PROBABILITY(int iValue);
	int getMAX_INTERCEPTION_PROBABILITY() const;

	void setSTANDARD_HANDICAP(int iValue);
	int getSTANDARD_HANDICAP() const;

	void setACO_SHOW_ATTACKER_INFO(int iValue);
	int getACO_SHOW_ATTACKER_INFO() const;

	void setBBAI_TURTLE_ENEMY_POWER_RATIO(int iValue);
	int getBBAI_TURTLE_ENEMY_POWER_RATIO() const;

	void setCONSCRIPT_POPULATION_PER_COST(int iValue);
	int getCONSCRIPT_POPULATION_PER_COST() const;

	void setGAMEFONT_TGA_RELIGIONS(int iValue);
	int getGAMEFONT_TGA_RELIGIONS() const;

	void setUSE_CAN_DO_PRODUCTION_CALLBACK(int iValue);
	int getUSE_CAN_DO_PRODUCTION_CALLBACK() const;

	void setBUILDING_PRODUCTION_PERCENT(int iValue);
	int getBUILDING_PRODUCTION_PERCENT() const;

	void setEVENT_MESSAGE_TIME_LONG(int iValue);
	int getEVENT_MESSAGE_TIME_LONG() const;

	void setMIN_INTERCEPTION_DAMAGE(int iValue);
	int getMIN_INTERCEPTION_DAMAGE() const;

	void setRIVER_RAND_ON_MORE_RIVERS(int iValue);
	int getRIVER_RAND_ON_MORE_RIVERS() const;

	void setSTANDARD_CALENDAR(int iValue);
	int getSTANDARD_CALENDAR() const;

	void setTEMPERATE_TERRAIN(int iValue);
	int getTEMPERATE_TERRAIN() const;

	void setUSE_CAN_DO_GROWTH_CALLBACK(int iValue);
	int getUSE_CAN_DO_GROWTH_CALLBACK() const;

	void setACO_SHOW_UNROUNDED_EXPERIENCE(int iValue);
	int getACO_SHOW_UNROUNDED_EXPERIENCE() const;

	void setCAPITAL_BUILDINGCLASS(int iValue);
	int getCAPITAL_BUILDINGCLASS() const;

	void setTECH_COST_FIRST_KNOWN_PREREQ_MODIFIER(int iValue);
	int getTECH_COST_FIRST_KNOWN_PREREQ_MODIFIER() const;

	void setUNIT_PRODUCTION_PERCENT(int iValue);
	int getUNIT_PRODUCTION_PERCENT() const;

	void setADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES(int iValue);
	int getADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES() const;

	void setBUG_CITYBAR_HURRY_ASSIST_INCLUDE_CURRENT(int iValue);
	int getBUG_CITYBAR_HURRY_ASSIST_INCLUDE_CURRENT() const;

	void setCURSOR_GO_TO(int iValue);
	int getCURSOR_GO_TO() const;

	void setFORCED_WAR_WAR_WEARINESS_MODIFIER(int iValue);
	int getFORCED_WAR_WAR_WEARINESS_MODIFIER() const;

	void setMIN_POP_CONSIDER_INQUISITORS(int iValue);
	int getMIN_POP_CONSIDER_INQUISITORS() const;

	void setNPC1_CIVILIZATION(int iValue);
	int getNPC1_CIVILIZATION() const;

	void setNPC2_CIVILIZATION(int iValue);
	int getNPC2_CIVILIZATION() const;

	void setNPC3_CIVILIZATION(int iValue);
	int getNPC3_CIVILIZATION() const;

	void setNPC4_CIVILIZATION(int iValue);
	int getNPC4_CIVILIZATION() const;

	void setNPC5_CIVILIZATION(int iValue);
	int getNPC5_CIVILIZATION() const;

	void setNPC6_CIVILIZATION(int iValue);
	int getNPC6_CIVILIZATION() const;

	void setNPC7_CIVILIZATION(int iValue);
	int getNPC7_CIVILIZATION() const;

	void setNPC8_CIVILIZATION(int iValue);
	int getNPC8_CIVILIZATION() const;

	void setRECON_VISIBILITY_RANGE(int iValue);
	int getRECON_VISIBILITY_RANGE() const;

	void setCAN_TRADE_GOLD_PER_TURN(int iValue);
	int getCAN_TRADE_GOLD_PER_TURN() const;

	void setDYNAMIC_CIV_NAMES(int iValue);
	int getDYNAMIC_CIV_NAMES() const;

	void setLAKE_MAX_AREA_SIZE(int iValue);
	int getLAKE_MAX_AREA_SIZE() const;

	void setMIN_WATER_SIZE_FOR_OCEAN(int iValue);
	int getMIN_WATER_SIZE_FOR_OCEAN() const;

	void setNUKE_POPULATION_DEATH_BASE(int iValue);
	int getNUKE_POPULATION_DEATH_BASE() const;

	void setNUKE_UNIT_DAMAGE_RAND_1(int iValue);
	int getNUKE_UNIT_DAMAGE_RAND_1() const;

	void setNUKE_UNIT_DAMAGE_RAND_2(int iValue);
	int getNUKE_UNIT_DAMAGE_RAND_2() const;

	void setPEAK_EXTRA_DEFENSE(int iValue);
	int getPEAK_EXTRA_DEFENSE() const;

	void setOCCUPATION_CULTURE_PERCENT_THRESHOLD(int iValue);
	int getOCCUPATION_CULTURE_PERCENT_THRESHOLD() const;

	void setBUG_BUILDING_SAVED_MAINTENANCE_HOVER(int iValue);
	int getBUG_BUILDING_SAVED_MAINTENANCE_HOVER() const;

	void setBUG_PRODUCTION_DECAY_HOVER_BUILDING_THRESHOLD(int iValue);
	int getBUG_PRODUCTION_DECAY_HOVER_BUILDING_THRESHOLD() const;

	void setBUG_PRODUCTION_DECAY_HOVER_UNIT_THRESHOLD(int iValue);
	int getBUG_PRODUCTION_DECAY_HOVER_UNIT_THRESHOLD() const;

	void setBUG_SPED_UP_TECHS_HOVER(int iValue);
	int getBUG_SPED_UP_TECHS_HOVER() const;

	void setCIVIC_ANARCHY_QTY_DISCOUNT(int iValue);
	int getCIVIC_ANARCHY_QTY_DISCOUNT() const;

	void setSAD_MAX_MODIFIER(int iValue);
	int getSAD_MAX_MODIFIER() const;

	void setWW_DECAY_PEACE_PERCENT(int iValue);
	int getWW_DECAY_PEACE_PERCENT() const;

	void setCAN_TRADE_WORKERS(int iValue);
	int getCAN_TRADE_WORKERS() const;

	void setFIRST_EVENT_DELAY_TURNS(int iValue);
	int getFIRST_EVENT_DELAY_TURNS() const;

	void setMAX_CITY_DEFENSE_DAMAGE(int iValue);
	int getMAX_CITY_DEFENSE_DAMAGE() const;

	void setUSE_CANNOT_HANDLE_ACTION_CALLBACK(int iValue);
	int getUSE_CANNOT_HANDLE_ACTION_CALLBACK() const;

	void setACO_SWAP_VIEWS(int iValue);
	int getACO_SWAP_VIEWS() const;

	void setBONUS_OBSOLETE_VALUE_MODIFIER(int iValue);
	int getBONUS_OBSOLETE_VALUE_MODIFIER() const;

	void setBUG_CITYBAR_HAPPINESS(int iValue);
	int getBUG_CITYBAR_HAPPINESS() const;

	void setBUG_CITY_SCREEN_BASE_COMMERCE_HOVER(int iValue);
	int getBUG_CITY_SCREEN_BASE_COMMERCE_HOVER() const;

	void setCITY_GROWTH_MULTIPLIER(int iValue);
	int getCITY_GROWTH_MULTIPLIER() const;

	void setEXTRA_YIELD(int iValue);
	int getEXTRA_YIELD() const;

	void setLAND_UNITS_CAN_ATTACK_WATER_CITIES(int iValue);
	int getLAND_UNITS_CAN_ATTACK_WATER_CITIES() const;

	void setPLOTS_PER_RIVER_EDGE_DIVISOR(int iValue);
	int getPLOTS_PER_RIVER_EDGE_DIVISOR() const;

	void setADVANCED_START_MAX_UNITS_PER_CITY(int iValue);
	int getADVANCED_START_MAX_UNITS_PER_CITY() const;

	void setRELIGION_PERCENT_ANGER(int iValue);
	int getRELIGION_PERCENT_ANGER() const;

	void setUSE_AI_UPDATE_UNIT_CALLBACK(int iValue);
	int getUSE_AI_UPDATE_UNIT_CALLBACK() const;

	void setESPIONAGE_DISTANCE_MULTIPLIER_MOD(int iValue);
	int getESPIONAGE_DISTANCE_MULTIPLIER_MOD() const;

	void setHIGH_TO_LOW_FIRST_TURN_CHECK(int iValue);
	int getHIGH_TO_LOW_FIRST_TURN_CHECK() const;

	void setZOOM_CITY_FOR_PRODUCTION_POPUP(int iValue);
	int getZOOM_CITY_FOR_PRODUCTION_POPUP() const;

	void setANIMAL_DAMAGE_PERCENT_AFTER_SUBDUE(int iValue);
	int getANIMAL_DAMAGE_PERCENT_AFTER_SUBDUE() const;

	void setMAX_INTERCEPTION_DAMAGE(int iValue);
	int getMAX_INTERCEPTION_DAMAGE() const;

	void setOVERSEAS_TRADE_MODIFIER(int iValue);
	int getOVERSEAS_TRADE_MODIFIER() const;

	void setPAGE_IN_DIST_ROUTE(int iValue);
	int getPAGE_IN_DIST_ROUTE() const;

	void setUSE_GET_BUILDING_COST_MOD_CALLBACK(int iValue);
	int getUSE_GET_BUILDING_COST_MOD_CALLBACK() const;

	void setBARBARIAN_MAX_XP_VALUE(int iValue);
	int getBARBARIAN_MAX_XP_VALUE() const;

	void setBBAI_AIR_COMBAT(int iValue);
	int getBBAI_AIR_COMBAT() const;

	void setBBAI_BOMBARD_ATTACK_CITY_MAX_STACK_FRACTION(int iValue);
	int getBBAI_BOMBARD_ATTACK_CITY_MAX_STACK_FRACTION() const;

	void setBBAI_BOMBARD_ATTACK_STACK_FRACTION(int iValue);
	int getBBAI_BOMBARD_ATTACK_STACK_FRACTION() const;

	void setCAN_TRADE_PEACE(int iValue);
	int getCAN_TRADE_PEACE() const;

	void setUSE_IS_VICTORY_CALLBACK(int iValue);
	int getUSE_IS_VICTORY_CALLBACK() const;

	void setUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK(int iValue);
	int getUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK() const;

	void setBASE_SPY_STEAL_PLANS_COST(int iValue);
	int getBASE_SPY_STEAL_PLANS_COST() const;

	void setMAXED_BUILDING_GOLD_PERCENT(int iValue);
	int getMAXED_BUILDING_GOLD_PERCENT() const;

	void setMULTIPLAYER_WAR_WEARINESS_MODIFIER(int iValue);
	int getMULTIPLAYER_WAR_WEARINESS_MODIFIER() const;

	void setTURN_LOG_MAX_HEIGHT(int iValue);
	int getTURN_LOG_MAX_HEIGHT() const;

	void setWATER_POTENTIAL_CITY_WORK_FOR_AREA(int iValue);
	int getWATER_POTENTIAL_CITY_WORK_FOR_AREA() const;

	void setESPIONAGE_CITY_RELIGION_STATE_MOD(int iValue);
	int getESPIONAGE_CITY_RELIGION_STATE_MOD() const;

	void setESTABLISH_MODIFIER_PER_TURN(int iValue);
	int getESTABLISH_MODIFIER_PER_TURN() const;

	void setHURRY_INFLATION_DECAY_RATE(int iValue);
	int getHURRY_INFLATION_DECAY_RATE() const;

	void setMAXED_UNIT_GOLD_PERCENT(int iValue);
	int getMAXED_UNIT_GOLD_PERCENT() const;

	void setRUINS_IMPROVEMENT(int iValue);
	int getRUINS_IMPROVEMENT() const;

	void setSCORE_HANDICAP_PERCENT_PER(int iValue);
	int getSCORE_HANDICAP_PERCENT_PER() const;

	void setUSE_CANNOT_SPREAD_RELIGION_CALLBACK(int iValue);
	int getUSE_CANNOT_SPREAD_RELIGION_CALLBACK() const;

	void setADVANCED_START_CITY_PLACEMENT_MAX_RANGE(int iValue);
	int getADVANCED_START_CITY_PLACEMENT_MAX_RANGE() const;

	void setRIVER_SOURCE_MIN_RIVER_RANGE(int iValue);
	int getRIVER_SOURCE_MIN_RIVER_RANGE() const;

	void setTECH_DIFFUSION_KNOWN_TEAM_MODIFIER(int iValue);
	int getTECH_DIFFUSION_KNOWN_TEAM_MODIFIER() const;

	void setADVANCED_START_VISIBILITY_COST_INCREASE(int iValue);
	int getADVANCED_START_VISIBILITY_COST_INCREASE() const;

	void setCAPTURE_GOLD_MAX_TURNS(int iValue);
	int getCAPTURE_GOLD_MAX_TURNS() const;

	void setCOMMERCE_ATTACKS_FADE_RATE(int iValue);
	int getCOMMERCE_ATTACKS_FADE_RATE() const;

	void setGOlDEN_AGE_PERCENT_LESS_FOOD_FOR_GROWTH(int iValue);
	int getGOlDEN_AGE_PERCENT_LESS_FOOD_FOR_GROWTH() const;

	void setBASE_REVOLT_OCCUPATION_TURNS(int iValue);
	int getBASE_REVOLT_OCCUPATION_TURNS() const;

	void setBUG_IGNORE_HARMLESS_BARBARIANS(int iValue);
	int getBUG_IGNORE_HARMLESS_BARBARIANS() const;

	void setCURSOR_EDIT(int iValue);
	int getCURSOR_EDIT() const;

	void setDRY_TERRAIN(int iValue);
	int getDRY_TERRAIN() const;

	void setOWN_TEAM_STARTING_MODIFIER(int iValue);
	int getOWN_TEAM_STARTING_MODIFIER() const;

	void setCAN_TRADE_DEFENSIVE_PACT(int iValue);
	int getCAN_TRADE_DEFENSIVE_PACT() const;

	void setESPIONAGE_CITY_POP_EACH_MOD(int iValue);
	int getESPIONAGE_CITY_POP_EACH_MOD() const;

	void setIDW_NO_BARBARIAN_INFLUENCE(int iValue);
	int getIDW_NO_BARBARIAN_INFLUENCE() const;

	void setNUM_JUNGLE_NAMES(int iValue);
	int getNUM_JUNGLE_NAMES() const;

	void setPASSIVE_ANIMAL_LEADER(int iValue);
	int getPASSIVE_ANIMAL_LEADER() const;

	void setADVANCED_START_POPULATION_COST_INCREASE(int iValue);
	int getADVANCED_START_POPULATION_COST_INCREASE() const;

	void setBUG_BUILDING_ADDITIONAL_PRODUCTION_HOVER(int iValue);
	int getBUG_BUILDING_ADDITIONAL_PRODUCTION_HOVER() const;

	void setOUR_POPULATION_TRADE_MODIFIER(int iValue);
	int getOUR_POPULATION_TRADE_MODIFIER() const;

	void setCOMBAT_DIE_SIDES(int iValue);
	int getCOMBAT_DIE_SIDES() const;

	void setFREE_TRADE_AGREEMENT_ESPIONAGE_MISSION_COST_MODIFIER(int iValue);
	int getFREE_TRADE_AGREEMENT_ESPIONAGE_MISSION_COST_MODIFIER() const;

	void setINITIAL_STATE_RELIGION_HAPPINESS(int iValue);
	int getINITIAL_STATE_RELIGION_HAPPINESS() const;

	void setMAX_HIT_POINTS(int iValue);
	int getMAX_HIT_POINTS() const;

	void setMAX_NATIONAL_WONDERS_PER_CITY(int iValue);
	int getMAX_NATIONAL_WONDERS_PER_CITY() const;

	void setPEAK_SEE_THROUGH_CHANGE(int iValue);
	int getPEAK_SEE_THROUGH_CHANGE() const;

	void setTURN_LOG_MIN_HEIGHT(int iValue);
	int getTURN_LOG_MIN_HEIGHT() const;

	void setBASE_REVOLT_FREE_UNITS(int iValue);
	int getBASE_REVOLT_FREE_UNITS() const;

	void setSIZE_MATTERS_MOST_MULTIPLIER(int iValue);
	int getSIZE_MATTERS_MOST_MULTIPLIER() const;

	void setUSE_CAN_MAINTAIN_PROCESS_CALLBACK(int iValue);
	int getUSE_CAN_MAINTAIN_PROCESS_CALLBACK() const;

	void setWASTAGE_START_CONSUMPTION_PERCENT(int iValue);
	int getWASTAGE_START_CONSUMPTION_PERCENT() const;

	void setBUG_ASK_DECLARE_WAR_UNITS(int iValue);
	int getBUG_ASK_DECLARE_WAR_UNITS() const;

	void setBUG_PLOT_HOVER_LAT_LONG(int iValue);
	int getBUG_PLOT_HOVER_LAT_LONG() const;

	void setGOLDEN_AGE_LENGTH(int iValue);
	int getGOLDEN_AGE_LENGTH() const;

	void setMAXED_PROJECT_GOLD_PERCENT(int iValue);
	int getMAXED_PROJECT_GOLD_PERCENT() const;

	void setMAX_ANARCHY_TURNS(int iValue);
	int getMAX_ANARCHY_TURNS() const;

	void setMAX_PLOT_LIST_ROWS(int iValue);
	int getMAX_PLOT_LIST_ROWS() const;

	void setMIN_VERSION(int iValue);
	int getMIN_VERSION() const;

	void setNUM_DESERT_NAMES(int iValue);
	int getNUM_DESERT_NAMES() const;

	void setSS_BRIBE(int iValue);
	int getSS_BRIBE() const;

	void setBARBARIAN_SPAWN_MODIFIER(int iValue);
	int getBARBARIAN_SPAWN_MODIFIER() const;

	void setCAN_TRADE_WAR(int iValue);
	int getCAN_TRADE_WAR() const;

	void setCITY_AIR_UNIT_CAPACITY(int iValue);
	int getCITY_AIR_UNIT_CAPACITY() const;

	void setNEUTRAL_HEAL_RATE(int iValue);
	int getNEUTRAL_HEAL_RATE() const;

	void setSCORE_POPULATION_FACTOR(int iValue);
	int getSCORE_POPULATION_FACTOR() const;

	void setUSE_MODDERS_PLAYEROPTION_1(int iValue);
	int getUSE_MODDERS_PLAYEROPTION_1() const;

	void setUSE_MODDERS_PLAYEROPTION_2(int iValue);
	int getUSE_MODDERS_PLAYEROPTION_2() const;

	void setUSE_MODDERS_PLAYEROPTION_3(int iValue);
	int getUSE_MODDERS_PLAYEROPTION_3() const;

	void setBBAI_HUMAN_VASSAL_WAR_BUILD(int iValue);
	int getBBAI_HUMAN_VASSAL_WAR_BUILD() const;

	void setCURSOR_LINK(int iValue);
	int getCURSOR_LINK() const;

	void setCURSOR_PING(int iValue);
	int getCURSOR_PING() const;

	void setESPIONAGE_SPY_INTERCEPT_MOD(int iValue);
	int getESPIONAGE_SPY_INTERCEPT_MOD() const;

	void setLANDMARK_ANGER_DIVISOR(int iValue);
	int getLANDMARK_ANGER_DIVISOR() const;

	void setMAX_TRADE_ROUTES(int iValue);
	int getMAX_TRADE_ROUTES() const;

	void setMAX_WITHDRAWAL_PROBABILITY(int iValue);
	int getMAX_WITHDRAWAL_PROBABILITY() const;

	void setNUM_FOREST_NAMES(int iValue);
	int getNUM_FOREST_NAMES() const;

	void setTAXATION_ANGER_ROUND_DOWN(int iValue);
	int getTAXATION_ANGER_ROUND_DOWN() const;

	void setBBAI_UNIT_CAPTURE(int iValue);
	int getBBAI_UNIT_CAPTURE() const;

	void setBUG_TECH_TRADE_DENIAL_HOVER(int iValue);
	int getBUG_TECH_TRADE_DENIAL_HOVER() const;

	void setCOMBAT_EXPERIENCE_IN_BORDERS_PERCENT(int iValue);
	int getCOMBAT_EXPERIENCE_IN_BORDERS_PERCENT() const;

	void setCULTURE_PERCENT_ANGER(int iValue);
	int getCULTURE_PERCENT_ANGER() const;

	void setDCM_AIR_BOMBING(int iValue);
	int getDCM_AIR_BOMBING() const;

	void setUSE_CAN_RAZE_CITY_CALLBACK(int iValue);
	int getUSE_CAN_RAZE_CITY_CALLBACK() const;

	void setAT_WAR_CULTURE_ANGER_MODIFIER(int iValue);
	int getAT_WAR_CULTURE_ANGER_MODIFIER() const;

	void setBASE_WAR_WEARINESS_MULTIPLIER(int iValue);
	int getBASE_WAR_WEARINESS_MULTIPLIER() const;

	void setBATTLE_EFFECT_LESS_FOOD(int iValue);
	int getBATTLE_EFFECT_LESS_FOOD() const;

	void setBUILDING_PRODUCTION_DECAY_TIME(int iValue);
	int getBUILDING_PRODUCTION_DECAY_TIME() const;

	void setINITIAL_TRADE_ROUTES(int iValue);
	int getINITIAL_TRADE_ROUTES() const;

	void setMAX_PLOT_LIST_SIZE(int iValue);
	int getMAX_PLOT_LIST_SIZE() const;

	void setRENDER_GLOBEVIEW_CLOUDS(int iValue);
	int getRENDER_GLOBEVIEW_CLOUDS() const;

	void setAI_WORKER_MAX_DISTANCE_FROM_CITY_OUT_BORDERS(int iValue);
	int getAI_WORKER_MAX_DISTANCE_FROM_CITY_OUT_BORDERS() const;

	void setUNIT_PRODUCTION_DECAY_TIME(int iValue);
	int getUNIT_PRODUCTION_DECAY_TIME() const;

	void setBUG_CITYBAR_TRADE_DETAIL(int iValue);
	int getBUG_CITYBAR_TRADE_DETAIL() const;

	void setCURSOR_GRIP(int iValue);
	int getCURSOR_GRIP() const;

	void setCURSOR_REBASE(int iValue);
	int getCURSOR_REBASE() const;

	void setDEFAULT_ANIM_PAGE_MAX(int iValue);
	int getDEFAULT_ANIM_PAGE_MAX() const;

	void setDIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT(int iValue);
	int getDIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT() const;

	void setMARSH_TERRAIN(int iValue);
	int getMARSH_TERRAIN() const;

	void setMOVE_DENOMINATOR(int iValue);
	int getMOVE_DENOMINATOR() const;

	void setWATER_IMPROVEMENT(int iValue);
	int getWATER_IMPROVEMENT() const;

	void setACO_SHOW_AVERAGE_HEALTH(int iValue);
	int getACO_SHOW_AVERAGE_HEALTH() const;

	void setBUG_BUILDING_HOVER_ACTUAL_EFFECTS(int iValue);
	int getBUG_BUILDING_HOVER_ACTUAL_EFFECTS() const;

	void setCORPORATION_SPREAD_DISTANCE_DIVISOR(int iValue);
	int getCORPORATION_SPREAD_DISTANCE_DIVISOR() const;

	void setCURSOR_NUKE(int iValue);
	int getCURSOR_NUKE() const;

	void setFREE_CITY_CULTURE(int iValue);
	int getFREE_CITY_CULTURE() const;

	void setGLOBAL_WARMING_POWER_WEIGHT(int iValue);
	int getGLOBAL_WARMING_POWER_WEIGHT() const;

	void setMAX_DESIRED_MEMORY_USED(int iValue);
	int getMAX_DESIRED_MEMORY_USED() const;

	void setPLAYER_ALWAYS_RAZES_CITIES(int iValue);
	int getPLAYER_ALWAYS_RAZES_CITIES() const;

	void setSEAWATER_SEE_THROUGH_CHANGE(int iValue);
	int getSEAWATER_SEE_THROUGH_CHANGE() const;

	void setSS_ENABLED(int iValue);
	int getSS_ENABLED() const;

	void setSTANDARD_SEALEVEL(int iValue);
	int getSTANDARD_SEALEVEL() const;

	void setTURN_LOG_MAX_WIDTH(int iValue);
	int getTURN_LOG_MAX_WIDTH() const;

	void setWAR_SUCCESS_NUKE(int iValue);
	int getWAR_SUCCESS_NUKE() const;

	void setACO_SHOW_SURVIVAL_ODDS(int iValue);
	int getACO_SHOW_SURVIVAL_ODDS() const;

	void setBUG_LEADERHEAD_HOVER_WORST_ENEMY(int iValue);
	int getBUG_LEADERHEAD_HOVER_WORST_ENEMY() const;

	void setCAPTURE_GOLD_PER_POPULATION(int iValue);
	int getCAPTURE_GOLD_PER_POPULATION() const;

	void setEMBASSY_ESPIONAGE_MISSION_COST_MODIFIER(int iValue);
	int getEMBASSY_ESPIONAGE_MISSION_COST_MODIFIER() const;

	void setRAND_CORPORATION_BEST_SPREAD(int iValue);
	int getRAND_CORPORATION_BEST_SPREAD() const;

	void setBUG_BUILDING_ADDITIONAL_HAPPINESS_HOVER(int iValue);
	int getBUG_BUILDING_ADDITIONAL_HAPPINESS_HOVER() const;

	void setCOLLATERAL_COMBAT_DAMAGE(int iValue);
	int getCOLLATERAL_COMBAT_DAMAGE() const;

	void setSAFE_GOLD_PERCENT(int iValue);
	int getSAFE_GOLD_PERCENT() const;

	void setSCORE_TECH_FACTOR(int iValue);
	int getSCORE_TECH_FACTOR() const;

	void setUSE_CAN_CREATE_PROJECT_CALLBACK(int iValue);
	int getUSE_CAN_CREATE_PROJECT_CALLBACK() const;

	void setGLOBAL_WARMING_NUKE_WEIGHT(int iValue);
	int getGLOBAL_WARMING_NUKE_WEIGHT() const;

	void setIDW_EMERGENCY_DRAFT_MIN_POPULATION(int iValue);
	int getIDW_EMERGENCY_DRAFT_MIN_POPULATION() const;

	void setINTERCEPTION_MAX_ROUNDS(int iValue);
	int getINTERCEPTION_MAX_ROUNDS() const;

	void setBBAI_SKIP_BOMBARD_MIN_STACK_RATIO(int iValue);
	int getBBAI_SKIP_BOMBARD_MIN_STACK_RATIO() const;

	void setCURSOR_MOVE(int iValue);
	int getCURSOR_MOVE() const;

	void setENABLE_VIEWPORTS(int iValue);
	int getENABLE_VIEWPORTS() const;

	void setESPIONAGE_INTERCEPT_SPENDING_MAX(int iValue);
	int getESPIONAGE_INTERCEPT_SPENDING_MAX() const;

	void setUSE_AI_BESTTECH_CALLBACK(int iValue);
	int getUSE_AI_BESTTECH_CALLBACK() const;

	void setWEEKS_PER_MONTHS(int iValue);
	int getWEEKS_PER_MONTHS() const;

	void setCAN_TRADE_LIMITED_BORDERS(int iValue);
	int getCAN_TRADE_LIMITED_BORDERS() const;

	void setMAX_AIRLIFT_RANGE(int iValue);
	int getMAX_AIRLIFT_RANGE() const;

	void setMAX_NATIONAL_WONDERS_PER_CITY_FOR_OCC(int iValue);
	int getMAX_NATIONAL_WONDERS_PER_CITY_FOR_OCC() const;

	void setNUM_ROUTE_PREREQ_OR_BONUSES(int iValue);
	int getNUM_ROUTE_PREREQ_OR_BONUSES() const;

	void setSCORE_LAND_FACTOR(int iValue);
	int getSCORE_LAND_FACTOR() const;

	void setUSE_CAN_DECLARE_WAR_CALLBACK(int iValue);
	int getUSE_CAN_DECLARE_WAR_CALLBACK() const;

	void setUSE_CAN_DO_GOLD_CALLBACK(int iValue);
	int getUSE_CAN_DO_GOLD_CALLBACK() const;

	void setBUG_LEADERHEAD_HOVER_DEFENSIVE_PACTS(int iValue);
	int getBUG_LEADERHEAD_HOVER_DEFENSIVE_PACTS() const;

	void setMAX_NUM_LANGUAGES(int iValue);
	int getMAX_NUM_LANGUAGES() const;

	void setSTANDARD_CLIMATE(int iValue);
	int getSTANDARD_CLIMATE() const;

	void setUSE_CAN_DO_CULTURE_CALLBACK(int iValue);
	int getUSE_CAN_DO_CULTURE_CALLBACK() const;

	void setBBAI_VICTORY_STRATEGY_SPACE(int iValue);
	int getBBAI_VICTORY_STRATEGY_SPACE() const;

	void setTRADE_PROFIT_PERCENT(int iValue);
	int getTRADE_PROFIT_PERCENT() const;

	void setBUG_PRODUCTION_DECAY_HOVER(int iValue);
	int getBUG_PRODUCTION_DECAY_HOVER() const;

	void setINITIAL_CITY_ROUTE_TYPE(int iValue);
	int getINITIAL_CITY_ROUTE_TYPE() const;

	void setWAR_SUCCESS_ATTACKING(int iValue);
	int getWAR_SUCCESS_ATTACKING() const;

	void setWAR_SUCCESS_DEFENDING(int iValue);
	int getWAR_SUCCESS_DEFENDING() const;

	void setWW_CAPTURED_CITY(int iValue);
	int getWW_CAPTURED_CITY() const;

	void setBASE_GOLDEN_AGE_UNITS(int iValue);
	int getBASE_GOLDEN_AGE_UNITS() const;

	void setCHOOSE_RELIGION(int iValue);
	int getCHOOSE_RELIGION() const;

	void setNUM_CORPORATION_PREREQ_BONUSES(int iValue);
	int getNUM_CORPORATION_PREREQ_BONUSES() const;

	void setSIZE_MATTERS_MOST_VOLUMETRIC_MULTIPLIER(int iValue);
	int getSIZE_MATTERS_MOST_VOLUMETRIC_MULTIPLIER() const;

	void setUSE_CAN_DO_GREATPEOPLE_CALLBACK(int iValue);
	int getUSE_CAN_DO_GREATPEOPLE_CALLBACK() const;

	void setUSE_EXTRA_PLAYER_COSTS_CALLBACK(int iValue);
	int getUSE_EXTRA_PLAYER_COSTS_CALLBACK() const;

	void setVASSAL_REVOLT_MASTER_LOSSES_FACTOR(int iValue);
	int getVASSAL_REVOLT_MASTER_LOSSES_FACTOR() const;

	void setADVANCED_START_CULTURE_COST_INCREASE(int iValue);
	int getADVANCED_START_CULTURE_COST_INCREASE() const;

	void setUSE_GET_UNIT_COST_MOD_CALLBACK(int iValue);
	int getUSE_GET_UNIT_COST_MOD_CALLBACK() const;

	void setBUG_BUILDING_ADDITIONAL_COMMERCE_HOVER(int iValue);
	int getBUG_BUILDING_ADDITIONAL_COMMERCE_HOVER() const;

	void setCITY_MAX_NUM_BUILDINGS(int iValue);
	int getCITY_MAX_NUM_BUILDINGS() const;

	void setUNIT_PRODUCTION_PERCENT_SM(int iValue);
	int getUNIT_PRODUCTION_PERCENT_SM() const;

	void setUSE_UPGRADE_UNIT_PRICE_CALLBACK(int iValue);
	int getUSE_UPGRADE_UNIT_PRICE_CALLBACK() const;

	void setVASSAL_HAPPINESS(int iValue);
	int getVASSAL_HAPPINESS() const;

	void setBUG_PRECHOP_IMPROVEMENTS(int iValue);
	int getBUG_PRECHOP_IMPROVEMENTS() const;

	void setCURSOR_AIRSTRIKE(int iValue);
	int getCURSOR_AIRSTRIKE() const;

	void setGOLDEN_AGE_GREAT_PEOPLE_MODIFIER(int iValue);
	int getGOLDEN_AGE_GREAT_PEOPLE_MODIFIER() const;

	void setIGNORE_PLOT_GROUP_FOR_TRADE_ROUTES(int iValue);
	int getIGNORE_PLOT_GROUP_FOR_TRADE_ROUTES() const;

	void setMIN_CITY_ATTACK_MODIFIER_FOR_SIEGE_TOWER(int iValue);
	int getMIN_CITY_ATTACK_MODIFIER_FOR_SIEGE_TOWER() const;

	void setBUG_BUILDING_ADDITIONAL_DEFENSE_HOVER(int iValue);
	int getBUG_BUILDING_ADDITIONAL_DEFENSE_HOVER() const;

	void setCITY_SCREEN_CLICK_WILL_EXIT(int iValue);
	int getCITY_SCREEN_CLICK_WILL_EXIT() const;

	void setOC_RESPAWN_HOLY_CITIES(int iValue);
	int getOC_RESPAWN_HOLY_CITIES() const;

	void setOWNERSHIP_SCORE_DURATION_THRESHOLD(int iValue);
	int getOWNERSHIP_SCORE_DURATION_THRESHOLD() const;

	void setREVOLT_TOTAL_CULTURE_MODIFIER(int iValue);
	int getREVOLT_TOTAL_CULTURE_MODIFIER() const;

	void setACO_MERGE_SHORT_BARS(int iValue);
	int getACO_MERGE_SHORT_BARS() const;

	void setINITIAL_FREE_OUTSIDE_UNITS(int iValue);
	int getINITIAL_FREE_OUTSIDE_UNITS() const;

	void setNUM_BAY_NAMES(int iValue);
	int getNUM_BAY_NAMES() const;

	void setPEAK_SEE_FROM_CHANGE(int iValue);
	int getPEAK_SEE_FROM_CHANGE() const;

	void setSPY_DESTROY_COST_MULTIPLIER_LIMITED(int iValue);
	int getSPY_DESTROY_COST_MULTIPLIER_LIMITED() const;

	void setWW_DECAY_RATE(int iValue);
	int getWW_DECAY_RATE() const;

	void setWW_HIT_BY_NUKE(int iValue);
	int getWW_HIT_BY_NUKE() const;

	void setDIPLO_VOTE_SECRETARY_GENERAL_INTERVAL(int iValue);
	int getDIPLO_VOTE_SECRETARY_GENERAL_INTERVAL() const;

	void setHILLS_EXTRA_MOVEMENT(int iValue);
	int getHILLS_EXTRA_MOVEMENT() const;

	void setKILLERRABBIT_SPAWN_MODIFIER(int iValue);
	int getKILLERRABBIT_SPAWN_MODIFIER() const;

	void setRAZING_CULTURAL_PERCENT_THRESHOLD(int iValue);
	int getRAZING_CULTURAL_PERCENT_THRESHOLD() const;

	void setWW_CAPTURED_UNIT(int iValue);
	int getWW_CAPTURED_UNIT() const;

	void setACO_SHOW_DEFENSE_MODIFIERS(int iValue);
	int getACO_SHOW_DEFENSE_MODIFIERS() const;

	void setBASE_CITY_GROWTH_THRESHOLD(int iValue);
	int getBASE_CITY_GROWTH_THRESHOLD() const;

	void setCURSOR_BUSY(int iValue);
	int getCURSOR_BUSY() const;

	void setESPIONAGE_INTERCEPT_COUNTERSPY(int iValue);
	int getESPIONAGE_INTERCEPT_COUNTERSPY() const;

	void setESPIONAGE_SPY_MISSION_ESCAPE_MOD(int iValue);
	int getESPIONAGE_SPY_MISSION_ESCAPE_MOD() const;

	void setGLOBAL_WARMING_BONUS_WEIGHT(int iValue);
	int getGLOBAL_WARMING_BONUS_WEIGHT() const;

	void setGLOBAL_WARMING_UNHEALTH_WEIGHT(int iValue);
	int getGLOBAL_WARMING_UNHEALTH_WEIGHT() const;

	void setINFILTRATE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT(int iValue);
	int getINFILTRATE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT() const;

	void setINITIAL_AI_CITY_PRODUCTION(int iValue);
	int getINITIAL_AI_CITY_PRODUCTION() const;

	void setUSE_AI_DO_DIPLO_CALLBACK(int iValue);
	int getUSE_AI_DO_DIPLO_CALLBACK() const;

	void setUSE_CAN_RESEARCH_CALLBACK(int iValue);
	int getUSE_CAN_RESEARCH_CALLBACK() const;

	void setBUG_CITYBAR_AIRPORT_ICONS(int iValue);
	int getBUG_CITYBAR_AIRPORT_ICONS() const;

	void setENEMY_HEAL_RATE(int iValue);
	int getENEMY_HEAL_RATE() const;

	void setFREE_CITY_ADJACENT_CULTURE(int iValue);
	int getFREE_CITY_ADJACENT_CULTURE() const;

	void setGREAT_PEOPLE_THRESHOLD_INCREASE_TEAM(int iValue);
	int getGREAT_PEOPLE_THRESHOLD_INCREASE_TEAM() const;

	void setIDW_INFLUENCE_RADIUS(int iValue);
	int getIDW_INFLUENCE_RADIUS() const;

	void setPERCENT_ANGER_DIVISOR(int iValue);
	int getPERCENT_ANGER_DIVISOR() const;

	void setRENDER_AREABORDER_UNDER_FEATURES(int iValue);
	int getRENDER_AREABORDER_UNDER_FEATURES() const;

	void setTECH_COST_TOTAL_KNOWN_TEAM_MODIFIER(int iValue);
	int getTECH_COST_TOTAL_KNOWN_TEAM_MODIFIER() const;

	void setWAR_SUCCESS_CITY_CAPTURING(int iValue);
	int getWAR_SUCCESS_CITY_CAPTURING() const;

	void setBUG_CITYBAR_CULTURE_TURNS(int iValue);
	int getBUG_CITYBAR_CULTURE_TURNS() const;

	void setMINIMUM_MOUNTAIN_RANGE_SIZE(int iValue);
	int getMINIMUM_MOUNTAIN_RANGE_SIZE() const;

	void setOCCUPATION_TURNS_POPULATION_PERCENT(int iValue);
	int getOCCUPATION_TURNS_POPULATION_PERCENT() const;

	void setPAGE_IN_DIST_CITY(int iValue);
	int getPAGE_IN_DIST_CITY() const;

	void setTEAM_VOTE_MIN_CANDIDATES(int iValue);
	int getTEAM_VOTE_MIN_CANDIDATES() const;

	void setUSE_AI_CHOOSE_PRODUCTION_CALLBACK(int iValue);
	int getUSE_AI_CHOOSE_PRODUCTION_CALLBACK() const;

	void setMIN_TIMER_UNIT_DOUBLE_MOVES(int iValue);
	int getMIN_TIMER_UNIT_DOUBLE_MOVES() const;

	void setPROJECT_PRODUCTION_PERCENT(int iValue);
	int getPROJECT_PRODUCTION_PERCENT() const;

	void setBUG_CONSCRIPT_LIMIT_HOVER(int iValue);
	int getBUG_CONSCRIPT_LIMIT_HOVER() const;

	void setGLOBAL_WARMING_FOREST(int iValue);
	int getGLOBAL_WARMING_FOREST() const;

	void setMAX_FORTIFY_TURNS(int iValue);
	int getMAX_FORTIFY_TURNS() const;

	void setWW_UNIT_CAPTURED(int iValue);
	int getWW_UNIT_CAPTURED() const;

	void setADVANCED_START_SIGHT_RANGE(int iValue);
	int getADVANCED_START_SIGHT_RANGE() const;

	void setBBAI_VICTORY_STRATEGY_DOMINATION(int iValue);
	int getBBAI_VICTORY_STRATEGY_DOMINATION() const;

	void setDISBANDING_EARNS_GOLD(int iValue);
	int getDISBANDING_EARNS_GOLD() const;

	void setTECH_DIFFUSION_WELFARE_THRESHOLD(int iValue);
	int getTECH_DIFFUSION_WELFARE_THRESHOLD() const;

	void setUSE_CAN_DO_RESEARCH_CALLBACK(int iValue);
	int getUSE_CAN_DO_RESEARCH_CALLBACK() const;

	void setBBAI_VICTORY_STRATEGY_DIPLOMACY(int iValue);
	int getBBAI_VICTORY_STRATEGY_DIPLOMACY() const;

	void setBUG_CITYBAR_GREAT_PERSON_TURNS(int iValue);
	int getBUG_CITYBAR_GREAT_PERSON_TURNS() const;

	void setMIN_BARBARIAN_STARTING_DISTANCE(int iValue);
	int getMIN_BARBARIAN_STARTING_DISTANCE() const;

	void setSEAWATER_SEE_FROM_CHANGE(int iValue);
	int getSEAWATER_SEE_FROM_CHANGE() const;

	void setUPSCALED_RESEARCH_COST_MODIFIER(int iValue);
	int getUPSCALED_RESEARCH_COST_MODIFIER() const;

	void setUSE_CAN_DO_RELIGION_CALLBACK(int iValue);
	int getUSE_CAN_DO_RELIGION_CALLBACK() const;

	void setCITY_BARBARIAN_DEFENSE_MODIFIER(int iValue);
	int getCITY_BARBARIAN_DEFENSE_MODIFIER() const;

	void setMAX_WORLD_WONDERS_PER_CITY(int iValue);
	int getMAX_WORLD_WONDERS_PER_CITY() const;

	void setPAGE_IN_DIST_UNIT(int iValue);
	int getPAGE_IN_DIST_UNIT() const;

	void setSTANDARD_ERA(int iValue);
	int getSTANDARD_ERA() const;

	void setBASE_CAPTURE_GOLD(int iValue);
	int getBASE_CAPTURE_GOLD() const;

	void setHILLS_SEE_FROM_CHANGE(int iValue);
	int getHILLS_SEE_FROM_CHANGE() const;

	void setLAND_IMPROVEMENT(int iValue);
	int getLAND_IMPROVEMENT() const;

	void setMAX_BATTLE_TURNS(int iValue);
	int getMAX_BATTLE_TURNS() const;

	void setSHOW_HIDDEN_ATTITUDE(int iValue);
	int getSHOW_HIDDEN_ATTITUDE() const;

	void setWAR_SUCCESS_UNIT_CAPTURING(int iValue);
	int getWAR_SUCCESS_UNIT_CAPTURING() const;

	void setBASE_OCCUPATION_TURNS(int iValue);
	int getBASE_OCCUPATION_TURNS() const;

	void setGREAT_GENERALS_THRESHOLD_INCREASE_TEAM(int iValue);
	int getGREAT_GENERALS_THRESHOLD_INCREASE_TEAM() const;

	void setBUG_CONSCRIPT_UNIT_HOVER(int iValue);
	int getBUG_CONSCRIPT_UNIT_HOVER() const;

	void setCURSOR_SIZENE(int iValue);
	int getCURSOR_SIZENE() const;

	void setESPIONAGE_CULTURE_MULTIPLIER_MOD(int iValue);
	int getESPIONAGE_CULTURE_MULTIPLIER_MOD() const;

	void setESPIONAGE_SPY_REVEAL_IDENTITY_PERCENT(int iValue);
	int getESPIONAGE_SPY_REVEAL_IDENTITY_PERCENT() const;

	void setGREAT_PEOPLE_THRESHOLD_INCREASE(int iValue);
	int getGREAT_PEOPLE_THRESHOLD_INCREASE() const;

	void setIDW_PILLAGE_INFLUENCE_ENABLED(int iValue);
	int getIDW_PILLAGE_INFLUENCE_ENABLED() const;

	void setINITIAL_BASE_FREE_MILITARY_UNITS(int iValue);
	int getINITIAL_BASE_FREE_MILITARY_UNITS() const;

	void setINITIAL_GOLD_PER_UNIT(int iValue);
	int getINITIAL_GOLD_PER_UNIT() const;

	void setNUKE_BUILDING_DESTRUCTION_PROB(int iValue);
	int getNUKE_BUILDING_DESTRUCTION_PROB() const;

	void setNUKE_FALLOUT_PROB(int iValue);
	int getNUKE_FALLOUT_PROB() const;

	void setNUM_AND_TECH_PREREQS(int iValue);
	int getNUM_AND_TECH_PREREQS() const;

	void setREVOLT_TEST_PROB(int iValue);
	int getREVOLT_TEST_PROB() const;

	void setUSE_CANNOT_FOUND_CITY_CALLBACK(int iValue);
	int getUSE_CANNOT_FOUND_CITY_CALLBACK() const;

	void setBARBARIAN_HANDICAP(int iValue);
	int getBARBARIAN_HANDICAP() const;

	void setBATTLE_EFFECT_LESS_COMMERCE(int iValue);
	int getBATTLE_EFFECT_LESS_COMMERCE() const;

	void setBBAI_HUMAN_AS_VASSAL_OPTION(int iValue);
	int getBBAI_HUMAN_AS_VASSAL_OPTION() const;

	void setBUG_BONUS_TRADE_DENIAL_HOVER(int iValue);
	int getBUG_BONUS_TRADE_DENIAL_HOVER() const;

	void setRELIGION_SPREAD_RAND(int iValue);
	int getRELIGION_SPREAD_RAND() const;

	void setCOLD_FEATURE(int iValue);
	int getCOLD_FEATURE() const;

	void setHILLS_SEE_THROUGH_CHANGE(int iValue);
	int getHILLS_SEE_THROUGH_CHANGE() const;

	void setHOLYCITY_REMOVAL_GOLD(int iValue);
	int getHOLYCITY_REMOVAL_GOLD() const;

	void setOC_MIN_REV_INDEX(int iValue);
	int getOC_MIN_REV_INDEX() const;

	void setUSE_CAN_DO_CIVIC_CALLBACK(int iValue);
	int getUSE_CAN_DO_CIVIC_CALLBACK() const;

	void setUSE_FINISH_TEXT_CALLBACK(int iValue);
	int getUSE_FINISH_TEXT_CALLBACK() const;

	void setUSE_SPIES_NO_ENTER_BORDERS(int iValue);
	int getUSE_SPIES_NO_ENTER_BORDERS() const;

	void setACO_IGNORE_BARB_FREE_WINS(int iValue);
	int getACO_IGNORE_BARB_FREE_WINS() const;

	void setAGGRESSIVE_ANIMAL_LEADER(int iValue);
	int getAGGRESSIVE_ANIMAL_LEADER() const;

	void setBUG_CITYBAR_HURRY_ASSIST(int iValue);
	int getBUG_CITYBAR_HURRY_ASSIST() const;

	void setCAN_TRADE_EMBASSIES(int iValue);
	int getCAN_TRADE_EMBASSIES() const;

	void setFREE_VASSAL_POPULATION_PERCENT(int iValue);
	int getFREE_VASSAL_POPULATION_PERCENT() const;

	void setUSE_CAN_BUILD_CALLBACK(int iValue);
	int getUSE_CAN_BUILD_CALLBACK() const;

	void setSCORE_VICTORY_PERCENT(int iValue);
	int getSCORE_VICTORY_PERCENT() const;

	void setUSE_IS_PLAYER_RESEARCH_CALLBACK(int iValue);
	int getUSE_IS_PLAYER_RESEARCH_CALLBACK() const;

	void setDIPLOMACY_VALUE_REMAINDER(int iValue);
	int getDIPLOMACY_VALUE_REMAINDER() const;

	void setBUG_CITYBAR_HEALTH(int iValue);
	int getBUG_CITYBAR_HEALTH() const;

	void setDEFY_RESOLUTION_POP_ANGER(int iValue);
	int getDEFY_RESOLUTION_POP_ANGER() const;

	void setMAX_BOMBARD_DEFENSE(int iValue);
	int getMAX_BOMBARD_DEFENSE() const;

	void setMAX_YIELD_STACK(int iValue);
	int getMAX_YIELD_STACK() const;

	void setGREAT_GENERALS_THRESHOLD(int iValue);
	int getGREAT_GENERALS_THRESHOLD() const;

	void setLAND_TERRAIN(int iValue);
	int getLAND_TERRAIN() const;

	void setCITY_FREE_CULTURE_GROWTH_FACTOR(int iValue);
	int getCITY_FREE_CULTURE_GROWTH_FACTOR() const;

	void setCITY_THIRD_RING_EXTRA_GROWTH_THRESHOLD_PERCENT(int iValue);
	int getCITY_THIRD_RING_EXTRA_GROWTH_THRESHOLD_PERCENT() const;

	void setBASE_FEATURE_PRODUCTION_PERCENT(int iValue);
	int getBASE_FEATURE_PRODUCTION_PERCENT() const;

	void setBUG_LEADERHEAD_HOVER_HIDDEN_ATTITUDE(int iValue);
	int getBUG_LEADERHEAD_HOVER_HIDDEN_ATTITUDE() const;

	void setCOLD_TERRAIN(int iValue);
	int getCOLD_TERRAIN() const;

	void setCURSOR_PARADROP(int iValue);
	int getCURSOR_PARADROP() const;

	void setDCM_FIGHTER_ENGAGE(int iValue);
	int getDCM_FIGHTER_ENGAGE() const;

	void setFORCE_UNOWNED_CITY_TIMER(int iValue);
	int getFORCE_UNOWNED_CITY_TIMER() const;

	void setRANGE_COMBAT_DAMAGE(int iValue);
	int getRANGE_COMBAT_DAMAGE() const;

	void setBUG_CDA_ZOOM_CITY_DETAILS(int iValue);
	int getBUG_CDA_ZOOM_CITY_DETAILS() const;

	void setBUG_HURRY_OVERFLOW_HOVER(int iValue);
	int getBUG_HURRY_OVERFLOW_HOVER() const;

	void setACO_DEBUG(int iValue);
	int getACO_DEBUG() const;

	void setCONSCRIPT_POP_ANGER(int iValue);
	int getCONSCRIPT_POP_ANGER() const;

	void setFREE_VASSAL_LAND_PERCENT(int iValue);
	int getFREE_VASSAL_LAND_PERCENT() const;

	void setHILLS_EXTRA_DEFENSE(int iValue);
	int getHILLS_EXTRA_DEFENSE() const;

	void setUNIT_GOLD_DISBAND_DIVISOR(int iValue);
	int getUNIT_GOLD_DISBAND_DIVISOR() const;

	void setUSE_AI_CAN_DO_WARPLANS_CALLBACK(int iValue);
	int getUSE_AI_CAN_DO_WARPLANS_CALLBACK() const;

	void setXML_LOGGING_ENABLED(int iValue);
	int getXML_LOGGING_ENABLED() const;

	void setPEAK_BUILD_TIME_MODIFIER(int iValue);
	int getPEAK_BUILD_TIME_MODIFIER() const;

	void setUPKEEP_POPULATION_OFFSET(int iValue);
	int getUPKEEP_POPULATION_OFFSET() const;

	void setCIV4_VERSION(int iValue);
	int getCIV4_VERSION() const;

	void setTECH_COST_KNOWN_PREREQ_MODIFIER(int iValue);
	int getTECH_COST_KNOWN_PREREQ_MODIFIER() const;

	void setBBAI_VICTORY_STRATEGY_CONQUEST(int iValue);
	int getBBAI_VICTORY_STRATEGY_CONQUEST() const;

	void setBUG_UPDATE_UNIT_NAME_ON_UPGRADE(int iValue);
	int getBUG_UPDATE_UNIT_NAME_ON_UPGRADE() const;

	void setDCM_ARCHER_BOMBARD(int iValue);
	int getDCM_ARCHER_BOMBARD() const;

	void setFOREIGN_TRADE_FULL_CREDIT_PEACE_TURNS(int iValue);
	int getFOREIGN_TRADE_FULL_CREDIT_PEACE_TURNS() const;

	void setNO_MILITARY_PERCENT_ANGER(int iValue);
	int getNO_MILITARY_PERCENT_ANGER() const;

	void setUSE_GET_CITY_FOUND_VALUE_CALLBACK(int iValue);
	int getUSE_GET_CITY_FOUND_VALUE_CALLBACK() const;

	void setACO_SHOW_TOTAL_DEFENSE_MODIFIER(int iValue);
	int getACO_SHOW_TOTAL_DEFENSE_MODIFIER() const;

	void setBUG_CITYBAR_REVOLT_CHANCE(int iValue);
	int getBUG_CITYBAR_REVOLT_CHANCE() const;

	void setBUG_UNIT_EXPERIENCE_HOVER(int iValue);
	int getBUG_UNIT_EXPERIENCE_HOVER() const;

	void setEXPERIENCE_FROM_WITHDRAWL(int iValue);
	int getEXPERIENCE_FROM_WITHDRAWL() const;

	void setUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK(int iValue);
	int getUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK() const;

	void setACO_SHOW_MODIFIER_LABELS(int iValue);
	int getACO_SHOW_MODIFIER_LABELS() const;

	void setAGGRESSIVE_ANIMAL_CIVILIZATION(int iValue);
	int getAGGRESSIVE_ANIMAL_CIVILIZATION() const;

	void setMIN_EXPERIENCE_PER_COMBAT(int iValue);
	int getMIN_EXPERIENCE_PER_COMBAT() const;

	void setNUKE_FEATURE(int iValue);
	int getNUKE_FEATURE() const;

	void setBUG_GREAT_PEOPLE_RATE_BREAKDOWN_HOVER(int iValue);
	int getBUG_GREAT_PEOPLE_RATE_BREAKDOWN_HOVER() const;

	void setCAN_TRADE_RELIGIONS(int iValue);
	int getCAN_TRADE_RELIGIONS() const;

	void setADVANCED_START_POPULATION_COST(int iValue);
	int getADVANCED_START_POPULATION_COST() const;

	void setCUT_LOSERS_TURN_INCREMENT(int iValue);
	int getCUT_LOSERS_TURN_INCREMENT() const;

	void setNUKE_NON_COMBAT_DEATH_THRESHOLD(int iValue);
	int getNUKE_NON_COMBAT_DEATH_THRESHOLD() const;

	void setADVANCED_START_VISIBILITY_COST(int iValue);
	int getADVANCED_START_VISIBILITY_COST() const;

	void setBUG_PRECHOP_FORESTS(int iValue);
	int getBUG_PRECHOP_FORESTS() const;

	void setINITIAL_FREE_MILITARY_UNITS_POPULATION_PERCENT(int iValue);
	int getINITIAL_FREE_MILITARY_UNITS_POPULATION_PERCENT() const;

	void setUSE_CANNOT_TRAIN_CALLBACK(int iValue);
	int getUSE_CANNOT_TRAIN_CALLBACK() const;

	void setFRESH_WATER_HEALTH_CHANGE(int iValue);
	int getFRESH_WATER_HEALTH_CHANGE() const;

	void setRENDER_WATER(int iValue);
	int getRENDER_WATER() const;

	void setWARM_FEATURE(int iValue);
	int getWARM_FEATURE() const;

	void setBONUS_COUNT_PERCENTAGE_MODIFIER_ON_MORE_RESOURCES(int iValue);
	int getBONUS_COUNT_PERCENTAGE_MODIFIER_ON_MORE_RESOURCES() const;

	void setNUM_BUILDING_PREREQ_OR_BONUSES(int iValue);
	int getNUM_BUILDING_PREREQ_OR_BONUSES() const;

	void setOUR_POPULATION_TRADE_MODIFIER_OFFSET(int iValue);
	int getOUR_POPULATION_TRADE_MODIFIER_OFFSET() const;

	void setREVOLT_OCCUPATION_TURNS_PERCENT(int iValue);
	int getREVOLT_OCCUPATION_TURNS_PERCENT() const;

	void setTECH_DIFFUSION_WELFARE_MODIFIER(int iValue);
	int getTECH_DIFFUSION_WELFARE_MODIFIER() const;

	void setCAPTURE_GOLD_RAND1(int iValue);
	int getCAPTURE_GOLD_RAND1() const;

	void setCAPTURE_GOLD_RAND2(int iValue);
	int getCAPTURE_GOLD_RAND2() const;

	void setCOLONY_NUM_FREE_DEFENDERS(int iValue);
	int getCOLONY_NUM_FREE_DEFENDERS() const;

	void setSTANDARD_GAMESPEED(int iValue);
	int getSTANDARD_GAMESPEED() const;

	void setTHEIR_POPULATION_TRADE_PERCENT(int iValue);
	int getTHEIR_POPULATION_TRADE_PERCENT() const;

	void setEVENT_MESSAGE_TIME(int iValue);
	int getEVENT_MESSAGE_TIME() const;

	void setSEA_ANIMAL_SPAWN_MODIFIER(int iValue);
	int getSEA_ANIMAL_SPAWN_MODIFIER() const;

	void setESPIONAGE_CITY_TRADE_ROUTE_MOD(int iValue);
	int getESPIONAGE_CITY_TRADE_ROUTE_MOD() const;

	void setINITIAL_NON_STATE_RELIGION_HAPPINESS(int iValue);
	int getINITIAL_NON_STATE_RELIGION_HAPPINESS() const;

	void setUPGRADE_ROUND_LIMIT(int iValue);
	int getUPGRADE_ROUND_LIMIT() const;

	void setVASSAL_REVOLT_OWN_LOSSES_FACTOR(int iValue);
	int getVASSAL_REVOLT_OWN_LOSSES_FACTOR() const;

	void setDCM_OPP_FIRE(int iValue);
	int getDCM_OPP_FIRE() const;

	void setSCORE_FREE_PERCENT(int iValue);
	int getSCORE_FREE_PERCENT() const;

	void setCAN_TRADE_RESOURCES(int iValue);
	int getCAN_TRADE_RESOURCES() const;

	void setMAX_EXPERIENCE_PER_COMBAT(int iValue);
	int getMAX_EXPERIENCE_PER_COMBAT() const;

	void setWW_KILLED_UNIT_DEFENDING(int iValue);
	int getWW_KILLED_UNIT_DEFENDING() const;

	void setBUG_BUILDING_ADDITIONAL_HEALTH_HOVER(int iValue);
	int getBUG_BUILDING_ADDITIONAL_HEALTH_HOVER() const;

	void setESPIONAGE_EACH_TURN_UNIT_COST_DECREASE(int iValue);
	int getESPIONAGE_EACH_TURN_UNIT_COST_DECREASE() const;

	void setACO_SHOW_EXPERIENCE_RANGE(int iValue);
	int getACO_SHOW_EXPERIENCE_RANGE() const;

	void setGREAT_WORKS_CULTURE_TURNS(int iValue);
	int getGREAT_WORKS_CULTURE_TURNS() const;

	void setSPY_STEAL_PLANS_COST_MULTIPLIER(int iValue);
	int getSPY_STEAL_PLANS_COST_MULTIPLIER() const;

	void setNUM_UNIT_AND_TECH_PREREQS(int iValue);
	int getNUM_UNIT_AND_TECH_PREREQS() const;

	void setSTARTING_DISTANCE_PERCENT(int iValue);
	int getSTARTING_DISTANCE_PERCENT() const;

	void setTREEHUGGER_DEFENSE_BONUS(int iValue);
	int getTREEHUGGER_DEFENSE_BONUS() const;

	void setDEEP_WATER_TERRAIN(int iValue);
	int getDEEP_WATER_TERRAIN() const;

	void setCORPORATION_FOREIGN_SPREAD_COST_PERCENT(int iValue);
	int getCORPORATION_FOREIGN_SPREAD_COST_PERCENT() const;

	void setFORTIFY_MODIFIER_PER_TURN(int iValue);
	int getFORTIFY_MODIFIER_PER_TURN() const;

	void setPEACE_TREATY_LENGTH(int iValue);
	int getPEACE_TREATY_LENGTH() const;

	void setWW_UNIT_KILLED_DEFENDING(int iValue);
	int getWW_UNIT_KILLED_DEFENDING() const;

	void setNUM_OR_TECH_PREREQS(int iValue);
	int getNUM_OR_TECH_PREREQS() const;

	void setSHIP_BLOCKADE_RANGE(int iValue);
	int getSHIP_BLOCKADE_RANGE() const;

	void setBUG_PRODUCTION_POPUP_TRAIN_MILITARY_UNITS_FOREVER(int iValue);
	int getBUG_PRODUCTION_POPUP_TRAIN_MILITARY_UNITS_FOREVER() const;

	void setDCM_BATTLE_EFFECTS(int iValue);
	int getDCM_BATTLE_EFFECTS() const;

	void setESCAPE_MODIFIER_PER_TURN(int iValue);
	int getESCAPE_MODIFIER_PER_TURN() const;

	void setPATH_DAMAGE_WEIGHT(int iValue);
	int getPATH_DAMAGE_WEIGHT() const;

	void setDEFAULT_SPECIALIST(int iValue);
	int getDEFAULT_SPECIALIST() const;

	void setCOMBAT_DAMAGE(int iValue);
	int getCOMBAT_DAMAGE() const;

	void setCURSOR_RECON(int iValue);
	int getCURSOR_RECON() const;

	void setFOUND_RELIGION_CITY_RAND(int iValue);
	int getFOUND_RELIGION_CITY_RAND() const;

	void setHURRY_POP_ANGER(int iValue);
	int getHURRY_POP_ANGER() const;

	void setMIN_CIV_STARTING_DISTANCE(int iValue);
	int getMIN_CIV_STARTING_DISTANCE() const;

	void setNEW_HURRY_MODIFIER(int iValue);
	int getNEW_HURRY_MODIFIER() const;

	void setSAVE_VERSION(int iValue);
	int getSAVE_VERSION() const;

	void setBUG_SENTRY_HEALING_ONLY_NEUTRAL(int iValue);
	int getBUG_SENTRY_HEALING_ONLY_NEUTRAL() const;

	void setINITIAL_FREE_UNITS_POPULATION_PERCENT(int iValue);
	int getINITIAL_FREE_UNITS_POPULATION_PERCENT() const;

	void setTECH_COST_MODIFIER(int iValue);
	int getTECH_COST_MODIFIER() const;

	void setBATTLE_EFFECTS_MINIMUM_TURN_INCREMENTS(int iValue);
	int getBATTLE_EFFECTS_MINIMUM_TURN_INCREMENTS() const;

	void setUSE_ON_UNIT_LOST_CALLBACK(int iValue);
	int getUSE_ON_UNIT_LOST_CALLBACK() const;

	void setCANNOT_CLAIM_OCEAN(int iValue);
	int getCANNOT_CLAIM_OCEAN() const;

	void setFOOD_CONSUMPTION_PER_POPULATION(int iValue);
	int getFOOD_CONSUMPTION_PER_POPULATION() const;

	void setNEANDERTHAL_SPAWN_MODIFIER(int iValue);
	int getNEANDERTHAL_SPAWN_MODIFIER() const;

	void setDCM_ACTIVE_DEFENSE(int iValue);
	int getDCM_ACTIVE_DEFENSE() const;

	void setBUG_PRODUCTION_POPUP_TRAIN_CIVILIAN_UNITS_FOREVER(int iValue);
	int getBUG_PRODUCTION_POPUP_TRAIN_CIVILIAN_UNITS_FOREVER() const;

	void setTECH_COST_EXTRA_TEAM_MEMBER_MODIFIER(int iValue);
	int getTECH_COST_EXTRA_TEAM_MEMBER_MODIFIER() const;

	void setBUG_SENTRY_HEALING(int iValue);
	int getBUG_SENTRY_HEALING() const;

	void setDIRTY_POWER_HEALTH_CHANGE(int iValue);
	int getDIRTY_POWER_HEALTH_CHANGE() const;

	void setHURRY_ANGER_DIVISOR(int iValue);
	int getHURRY_ANGER_DIVISOR() const;

	void setNO_MILITARY_UNIT_TRADING(int iValue);
	int getNO_MILITARY_UNIT_TRADING() const;

	void setSTANDARD_TURNTIMER(int iValue);
	int getSTANDARD_TURNTIMER() const;

	void setWW_KILLED_UNIT_ATTACKING(int iValue);
	int getWW_KILLED_UNIT_ATTACKING() const;

	void setFEATURE_PRODUCTION_PERCENT_MULTIPLIER(int iValue);
	int getFEATURE_PRODUCTION_PERCENT_MULTIPLIER() const;

	void setANIMAL_MAX_XP_VALUE(int iValue);
	int getANIMAL_MAX_XP_VALUE() const;

	void setDCM_RB_CITYBOMBARD_CHANCE(int iValue);
	int getDCM_RB_CITYBOMBARD_CHANCE() const;

	void setUSE_CANNOT_MAINTAIN_PROCESS_CALLBACK(int iValue);
	int getUSE_CANNOT_MAINTAIN_PROCESS_CALLBACK() const;

	void setBASE_RESEARCH_RATE(int iValue);
	int getBASE_RESEARCH_RATE() const;

	void setCAMERA_FORCE_TO_SMALLEST_MAX_DISTANCE(int iValue);
	int getCAMERA_FORCE_TO_SMALLEST_MAX_DISTANCE() const;

	void setDCM_ATTACK_SUPPORT(int iValue);
	int getDCM_ATTACK_SUPPORT() const;

	void setFRIENDLY_HEAL_RATE(int iValue);
	int getFRIENDLY_HEAL_RATE() const;

	void setMAX_UNIT_VISIBILITY_RANGE(int iValue);
	int getMAX_UNIT_VISIBILITY_RANGE() const;

	void setCURSOR_SIZEH(int iValue);
	int getCURSOR_SIZEH() const;

	void setESPIONAGE_MISSION_COST_END_TOTAL_PERCENT_ADJUSTMENT(int iValue);
	int getESPIONAGE_MISSION_COST_END_TOTAL_PERCENT_ADJUSTMENT() const;

	void setPASSIVE_ANIMAL_CIVILIZATION(int iValue);
	int getPASSIVE_ANIMAL_CIVILIZATION() const;

	void setREVOLT_DEFENSE_STATE_RELIGION_MODIFIER(int iValue);
	int getREVOLT_DEFENSE_STATE_RELIGION_MODIFIER() const;

	void setREVOLT_OFFENSE_STATE_RELIGION_MODIFIER(int iValue);
	int getREVOLT_OFFENSE_STATE_RELIGION_MODIFIER() const;

	void setUPKEEP_CITY_OFFSET(int iValue);
	int getUPKEEP_CITY_OFFSET() const;

	void setBUG_CITYBAR_BUILDING_ICONS(int iValue);
	int getBUG_CITYBAR_BUILDING_ICONS() const;

	void setGAMEFONT_TGA_CORPORATIONS(int iValue);
	int getGAMEFONT_TGA_CORPORATIONS() const;

	void setMINIMUM_JUNGLE_SIZE(int iValue);
	int getMINIMUM_JUNGLE_SIZE() const;

	void setWW_UNIT_KILLED_ATTACKING(int iValue);
	int getWW_UNIT_KILLED_ATTACKING() const;

	void setCIRCUMNAVIGATE_FREE_MOVES(int iValue);
	int getCIRCUMNAVIGATE_FREE_MOVES() const;

	void setMAX_PAGING_FRAME_TIME_MS(int iValue);
	int getMAX_PAGING_FRAME_TIME_MS() const;

	void setREVOLT_FREE_UNITS_PERCENT(int iValue);
	int getREVOLT_FREE_UNITS_PERCENT() const;

	void setESPIONAGE_SPY_NO_INTRUDE_INTERCEPT_MOD(int iValue);
	int getESPIONAGE_SPY_NO_INTRUDE_INTERCEPT_MOD() const;

	void setGLOBAL_WARMING_PROB(int iValue);
	int getGLOBAL_WARMING_PROB() const;

	void setIDW_EMERGENCY_DRAFT_ENABLED(int iValue);
	int getIDW_EMERGENCY_DRAFT_ENABLED() const;

	void setNUCLEAR_WINTER_PROB(int iValue);
	int getNUCLEAR_WINTER_PROB() const;

	void setMINIMAP_RENDER_SIZE(int iValue);
	int getMINIMAP_RENDER_SIZE() const;

	void setSCORE_WONDER_FACTOR(int iValue);
	int getSCORE_WONDER_FACTOR() const;

	void setADVANCED_START_CITY_COST(int iValue);
	int getADVANCED_START_CITY_COST() const;

	void setMINIMUM_DESERT_SIZE(int iValue);
	int getMINIMUM_DESERT_SIZE() const;

	void setHOLY_CITY_INFLUENCE(int iValue);
	int getHOLY_CITY_INFLUENCE() const;

	void setUSE_CAN_DO_COMBAT_CALLBACK(int iValue);
	int getUSE_CAN_DO_COMBAT_CALLBACK() const;

	void setACO_SHOW_BASIC_INFO(int iValue);
	int getACO_SHOW_BASIC_INFO() const;

	void setMINIMUM_FOREST_SIZE(int iValue);
	int getMINIMUM_FOREST_SIZE() const;

	void setNUM_MOUNTAINS_NAMES(int iValue);
	int getNUM_MOUNTAINS_NAMES() const;

	void setNUM_WARNING_REVOLTS(int iValue);
	int getNUM_WARNING_REVOLTS() const;

	void setPAGE_IN_DIST_RIVER(int iValue);
	int getPAGE_IN_DIST_RIVER() const;

	void setRANGED_ATTACKS_USE_MOVES(int iValue);
	int getRANGED_ATTACKS_USE_MOVES() const;

	void setBARBARIAN_FREE_TECH_PERCENT(int iValue);
	int getBARBARIAN_FREE_TECH_PERCENT() const;

	void setBUG_CITYBAR_BASE_PRODUCTION(int iValue);
	int getBUG_CITYBAR_BASE_PRODUCTION() const;

	void setMAX_TEAM_WONDERS_PER_CITY(int iValue);
	int getMAX_TEAM_WONDERS_PER_CITY() const;

	void setMORE_XP_TO_LEVEL_MODIFIER(int iValue);
	int getMORE_XP_TO_LEVEL_MODIFIER() const;

	void setPOWER_HEALTH_CHANGE(int iValue);
	int getPOWER_HEALTH_CHANGE() const;

	void setBUG_CITYBAR_COMMERCE(int iValue);
	int getBUG_CITYBAR_COMMERCE() const;

	void setUSE_CAN_CONSTRUCT_CALLBACK(int iValue);
	int getUSE_CAN_CONSTRUCT_CALLBACK() const;

	void setCURSOR_ROUTE_TO(int iValue);
	int getCURSOR_ROUTE_TO() const;

	void setCURSOR_SIZEV(int iValue);
	int getCURSOR_SIZEV() const;

	void setRIVER_SOURCE_MIN_SEAWATER_RANGE(int iValue);
	int getRIVER_SOURCE_MIN_SEAWATER_RANGE() const;

	void setUNIT_ANIM_PAGE_MAX(int iValue);
	int getUNIT_ANIM_PAGE_MAX() const;

	void setWORKER_TRADE_VALUE_PERCENT_ADJUSTMENT(int iValue);
	int getWORKER_TRADE_VALUE_PERCENT_ADJUSTMENT() const;

	void setMIN_BARBARIAN_CITY_STARTING_DISTANCE(int iValue);
	int getMIN_BARBARIAN_CITY_STARTING_DISTANCE() const;

	void setVIEWPORT_SIZE_X(int iValue);
	int getVIEWPORT_SIZE_X() const;

	void setEVENT_MESSAGE_STAGGER_TIME(int iValue);
	int getEVENT_MESSAGE_STAGGER_TIME() const;

	void setFOUND_CORPORATION_CITY_RAND(int iValue);
	int getFOUND_CORPORATION_CITY_RAND() const;

	void setPEAK_EXTRA_MOVEMENT(int iValue);
	int getPEAK_EXTRA_MOVEMENT() const;

	void setVIEWPORT_SIZE_Y(int iValue);
	int getVIEWPORT_SIZE_Y() const;

	void setIDW_FORT_CAPTURE_MULTIPLIER(float fValue);
	float getIDW_FORT_CAPTURE_MULTIPLIER() const;

	void setGAME_CITY_SIZE_LINMAP_AT_0(float fValue);
	float getGAME_CITY_SIZE_LINMAP_AT_0() const;

	void setGAME_CITY_SIZE_LINMAP_AT_50(float fValue);
	float getGAME_CITY_SIZE_LINMAP_AT_50() const;

	void setFLAG_OFFSET2_X(float fValue);
	float getFLAG_OFFSET2_X() const;

	void setUNIT_TRAIL_RESOLUTION(float fValue);
	float getUNIT_TRAIL_RESOLUTION() const;

	void setFLAG_OFFSET2_Y(float fValue);
	float getFLAG_OFFSET2_Y() const;

	void setCAMERA_START_DISTANCE(float fValue);
	float getCAMERA_START_DISTANCE() const;

	void setCAMERA_SMALLEST_MAX_DISTANCE(float fValue);
	float getCAMERA_SMALLEST_MAX_DISTANCE() const;

	void setIDW_EMERGENCY_DRAFT_STRENGTH(float fValue);
	float getIDW_EMERGENCY_DRAFT_STRENGTH() const;

	void setGAME_CITY_SIZE_EXP_MODIFIER(float fValue);
	float getGAME_CITY_SIZE_EXP_MODIFIER() const;

	void setCAMERA_MIN_YAW(float fValue);
	float getCAMERA_MIN_YAW() const;

	void setCAMERA_MAX_YAW(float fValue);
	float getCAMERA_MAX_YAW() const;

	void setFOW_MINIMAP_WAS_VISIBLE_COLOR(float fValue);
	float getFOW_MINIMAP_WAS_VISIBLE_COLOR() const;

	void setBONUS_SCALE(float fValue);
	float getBONUS_SCALE() const;

	void setIDW_WARLORD_MULTIPLIER(float fValue);
	float getIDW_WARLORD_MULTIPLIER() const;

	void setCAMERA_CITY_ZOOM_IN_DISTANCE(float fValue);
	float getCAMERA_CITY_ZOOM_IN_DISTANCE() const;

	void setCAMERA_MIN_DISTANCE(float fValue);
	float getCAMERA_MIN_DISTANCE() const;

	void setCAMERA_MAX_SCROLL_SPEED(float fValue);
	float getCAMERA_MAX_SCROLL_SPEED() const;

	void setPLOT_SIZE(float fValue);
	float getPLOT_SIZE() const;

	void setIMPROVEMENT_SCALE(float fValue);
	float getIMPROVEMENT_SCALE() const;

	void setAIR_DEFEND_FINISH(float fValue);
	float getAIR_DEFEND_FINISH() const;

	void setCAMERA_MAX_TURN_OFFSET(float fValue);
	float getCAMERA_MAX_TURN_OFFSET() const;

	void setCAMERA_MIN_SCROLL_SPEED(float fValue);
	float getCAMERA_MIN_SCROLL_SPEED() const;

	void setCAMERA_NEAR_FAR_PLANE_RATIO(float fValue);
	float getCAMERA_NEAR_FAR_PLANE_RATIO() const;

	void setAIR_PATROL_RADIUS(float fValue);
	float getAIR_PATROL_RADIUS() const;

	void setCAMERA_MAX_TRAVEL_DISTANCE(float fValue);
	float getCAMERA_MAX_TRAVEL_DISTANCE() const;

	void setAIR_IDLE_HEIGHT(float fValue);
	float getAIR_IDLE_HEIGHT() const;

	void setAIR_PATROL_HEIGHT(float fValue);
	float getAIR_PATROL_HEIGHT() const;

	void setIDW_BASE_PILLAGE_INFLUENCE(float fValue);
	float getIDW_BASE_PILLAGE_INFLUENCE() const;

	void setFIELD_OF_VIEW(float fValue);
	float getFIELD_OF_VIEW() const;

	void setAIR_BOMB_HEIGHT(float fValue);
	float getAIR_BOMB_HEIGHT() const;

	void setFLAG_OFFSET_X(float fValue);
	float getFLAG_OFFSET_X() const;

	void setFLAG_OFFSET_Y(float fValue);
	float getFLAG_OFFSET_Y() const;

	void setHEALTH_BAR_WIDTH(float fValue);
	float getHEALTH_BAR_WIDTH() const;

	void setAIR_PATROL_SPEED(float fValue);
	float getAIR_PATROL_SPEED() const;

	void setSINGLE_UNIT_GFX_EXTRA_SCALE(float fValue);
	float getSINGLE_UNIT_GFX_EXTRA_SCALE() const;

	void setIDW_WINNER_PLOT_MULTIPLIER(float fValue);
	float getIDW_WINNER_PLOT_MULTIPLIER() const;

	void setCAMERA_SPECIAL_PITCH(float fValue);
	float getCAMERA_SPECIAL_PITCH() const;

	void setGAME_CITY_SIZE_MAX_PERCENT_UNIQUE(float fValue);
	float getGAME_CITY_SIZE_MAX_PERCENT_UNIQUE() const;

	void setIDW_EXPERIENCE_FACTOR(float fValue);
	float getIDW_EXPERIENCE_FACTOR() const;

	void setFOW_WAS_VISIBLE_COLOR(float fValue);
	float getFOW_WAS_VISIBLE_COLOR() const;

	void setSAD_FACTOR_1(float fValue);
	float getSAD_FACTOR_1() const;

	void setSAD_FACTOR_2(float fValue);
	float getSAD_FACTOR_2() const;

	void setCAMERA_SHRINE_ZOOM_IN_DISTANCE(float fValue);
	float getCAMERA_SHRINE_ZOOM_IN_DISTANCE() const;

	void setSAD_FACTOR_3(float fValue);
	float getSAD_FACTOR_3() const;

	void setCAMERA_CITY_TURN(float fValue);
	float getCAMERA_CITY_TURN() const;

	void setSAD_FACTOR_4(float fValue);
	float getSAD_FACTOR_4() const;

	void setCAMERA_BATTLE_ZOOM_IN_DISTANCE(float fValue);
	float getCAMERA_BATTLE_ZOOM_IN_DISTANCE() const;

	void setSHADOW_SCALE(float fValue);
	float getSHADOW_SCALE() const;

	void setWASTAGE_GROWTH_FACTOR(float fValue);
	float getWASTAGE_GROWTH_FACTOR() const;

	void setIDW_CITY_TILE_MULTIPLIER(float fValue);
	float getIDW_CITY_TILE_MULTIPLIER() const;

	void setAIR_EXECUTE_FINISH(float fValue);
	float getAIR_EXECUTE_FINISH() const;

	void setIDW_PLOT_DISTANCE_FACTOR(float fValue);
	float getIDW_PLOT_DISTANCE_FACTOR() const;

	void setEFFECT_DEFAULT_SIZE(float fValue);
	float getEFFECT_DEFAULT_SIZE() const;

	void setIDW_BASE_COMBAT_INFLUENCE(float fValue);
	float getIDW_BASE_COMBAT_INFLUENCE() const;

	void setIDW_NO_CITY_DEFENDER_MULTIPLIER(float fValue);
	float getIDW_NO_CITY_DEFENDER_MULTIPLIER() const;

	void setCAMERA_FAR_CLIP_Z_HEIGHT(float fValue);
	float getCAMERA_FAR_CLIP_Z_HEIGHT() const;

	void setAIR_DEFEND_DISTANCE(float fValue);
	float getAIR_DEFEND_DISTANCE() const;

	void setIDW_EMERGENCY_DRAFT_ANGER_MULTIPLIER(float fValue);
	float getIDW_EMERGENCY_DRAFT_ANGER_MULTIPLIER() const;

	void setRIVER_Z_BIAS(float fValue);
	float getRIVER_Z_BIAS() const;

	void setCAMERA_LOWER_PITCH(float fValue);
	float getCAMERA_LOWER_PITCH() const;

	void setCAMERA_UPPER_PITCH(float fValue);
	float getCAMERA_UPPER_PITCH() const;

	void setROUTE_Z_BIAS(float fValue);
	float getROUTE_Z_BIAS() const;

	void setIDW_LOSER_PLOT_MULTIPLIER(float fValue);
	float getIDW_LOSER_PLOT_MULTIPLIER() const;

	void setAIR_EXECUTE_DISTANCE(float fValue);
	float getAIR_EXECUTE_DISTANCE() const;

	void setUNIT_MULTISELECT_DISTANCE(float fValue);
	float getUNIT_MULTISELECT_DISTANCE() const;

	void setGAME_CITY_SIZE_METHOD(const char* szValue);
	const char* getGAME_CITY_SIZE_METHOD() const;

	void setC2C_VERSION(const char* szValue);
	const char* getC2C_VERSION() const;

	void setLEADERHEAD_RANDOM(const char* szValue);
	const char* getLEADERHEAD_RANDOM() const;

	void setLANGUAGE(const char* szValue);
	const char* getLANGUAGE() const;

	void setPROFILER_ALTERNATE_SAMPLE_SET_SOURCE(const char* szValue);
	const char* getPROFILER_ALTERNATE_SAMPLE_SET_SOURCE() const;

	void setQUICKSAVE(const char* szValue);
	const char* getQUICKSAVE() const;

	void setENABLE_BACKGROUND_PROFILING(bool bValue);
	bool getENABLE_BACKGROUND_PROFILING() const;

	void setDONT_ESCORT_SUBDUED_SEA_ANIMAL(bool bValue);
	bool getDONT_ESCORT_SUBDUED_SEA_ANIMAL() const;

	void setDYNAMIC_GREAT_WALL(bool bValue);
	bool getDYNAMIC_GREAT_WALL() const;

	void setDONT_ESCORT_SUBDUED_LAND_ANIMAL(bool bValue);
	bool getDONT_ESCORT_SUBDUED_LAND_ANIMAL() const;


protected:
	int8_t m_iANIMAL_SPAWN_MODIFIER;
	int8_t m_iC2C_MIN_PROP_CONTROL;
	int8_t m_iCURSOR_SPLITH;
	int8_t m_iUSE_CANNOT_RESEARCH_CALLBACK;
	int8_t m_iMINIMUM_PLAYERS_WITH_TECH_FOR_AUTO_CORPORATION_FOUNDING;
	int8_t m_iNUKE_UNIT_DAMAGE_BASE;
	int8_t m_iRIVER_ATTACK_MODIFIER;
	int8_t m_iRIVER_EXTRA_MOVEMENT;
	int8_t m_iBUG_HURRY_OVERFLOW_HOVER_INCLUDE_CURRENT;
	int8_t m_iCORPORATION_FOUND_CHECK_TURNS;
	int8_t m_iBUG_CITYBAR_DRAFT_ANGER;
	int8_t m_iBUG_CITY_SCREEN_REMOVE_SPECIALIST_HOVER;
	int8_t m_iMIN_CONVERSION_TURNS;
	int8_t m_iMIN_ANIMAL_STARTING_DISTANCE;
	int8_t m_iRELIGION_REMOVAL_GOLD;
	int8_t m_iTECH_DIFFUSION_ENABLE;
	int8_t m_iUSE_ON_UNIT_SET_XY_CALLBACK;
	int8_t m_iTEMP_HAPPY;
	int8_t m_iACO_SHOW_SHIFT_INSTRUCTIONS;
	int8_t m_iUSE_CANNOT_DO_CIVIC_CALLBACK;
	int8_t m_iUSE_CAN_DO_MELTDOWN_CALLBACK;
	int8_t m_iAI_CAN_DISBAND_UNITS;
	int8_t m_iPLOTS_PER_RIVER_EDGE;
	int8_t m_iUNIT_VISIBILITY_RANGE;
	int8_t m_iPLOT_VISIBILITY_RANGE;
	int8_t m_iSHALLOW_WATER_TERRAIN;
	uint8_t m_iSHOW_BUILDINGS_LEVEL;
	int8_t m_iCAMERA_CITY_NO_PITCH;
	int8_t m_iCONSCRIPT_MIN_CULTURE_PERCENT;
	int16_t m_iWE_LOVE_THE_KING_RAND;
	int8_t m_iACO_ENABLED;
	int8_t m_iCURSOR_SIZENW;
	int8_t m_iNEW_CITY_BUILDING_VALUE_MODIFIER;
	int8_t m_iNPC1_LEADER;
	int32_t m_iSTART_YEAR;
	int8_t m_iUSE_ON_UNIT_CREATED_CALLBACK;
	int8_t m_iBANDIT_SPAWN_MODIFIER;
	int8_t m_iCURSOR_SPLITV;
	int8_t m_iNPC2_LEADER;
	int8_t m_iGOLDEN_AGE_UNITS_MULTIPLIER;
	int8_t m_iNPC3_LEADER;
	int8_t m_iAI_HANDICAP;
	int8_t m_iNPC4_LEADER;
	int16_t m_iPAGE_IN_DIST_SYMBOLS;
	int8_t m_iCITY_DEFENSE_DAMAGE_HEAL_RATE;
	int8_t m_iDEFAULT_FLEXIBLE_DIFFICULTY_TURN_INCREMENTS;
	int8_t m_iNPC5_LEADER;
	int8_t m_iUSE_CAN_TRAIN_CALLBACK;
	int8_t m_iNPC6_LEADER;
	int8_t m_iNPC7_LEADER;
	int8_t m_iNUM_UNIT_PREREQ_OR_BONUSES;
	int8_t m_iBASE_RELIGION_ANARCHY_LENGTH;
	int8_t m_iFOREIGN_TRADE_MODIFIER;
	int8_t m_iNPC8_LEADER;
	int8_t m_iPAGE_IN_DIST_FEATURES;
	int8_t m_iSPY_DESTROY_COST_MULTIPLIER;
	int8_t m_iCAN_TRADE_GOLD;
	int8_t m_iWAR_PRIZES;
	int8_t m_iCAN_TRADE_CORPORATIONS;
	int8_t m_iGW_MOD_ENABLED;
	int8_t m_iLIMITED_RELIGIONS_EXCEPTIONS;
	int8_t m_iUNIT_MULTISELECT_MAX;
	int8_t m_iWARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT;
	int8_t m_iCAPITAL_TRADE_MODIFIER;
	int8_t m_iCOMMERCE_PERCENT_CHANGE_INCREMENTS;
	int8_t m_iUSE_CAN_DO_PLOT_CULTURE_CALLBACK;
	int8_t m_iINCREASING_DIFFICULTY_TURN_CHECK_INCREMENTS;
	int8_t m_iCITY_SCREEN_FOG_ENABLED;
	int8_t m_iGREAT_GENERALS_THRESHOLD_INCREASE;
	int8_t m_iNUM_BUILDING_AND_TECH_PREREQS;
	int8_t m_iTRADE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT;
	int8_t m_iBUG_UNIT_EXPERIENCE_MODIFIERS_HOVER;
	int8_t m_iUNIT_UPGRADE_COST_PER_PRODUCTION;
	int8_t m_iACO_SHOW_DEFENDER_HEALTH_BARS;
	int8_t m_iBARREN_TERRAIN;
	int8_t m_iIDW_ENABLED;
	int8_t m_iTREAT_NEGATIVE_GOLD_AS_MAINTENANCE;
	int8_t m_iBUG_CITYBAR_HURRY_ANGER;
	int8_t m_iCONSCRIPT_MIN_CITY_POPULATION;
	int8_t m_iDEFY_RESOLUTION_ANGER_DIVISOR;
	int8_t m_iCAN_TRADE_MAPS;
	int8_t m_iCORPORATION_RESOURCE_BASE_INFLUENCE;
	int8_t m_iACO_FORCE_ORIGINAL_ODDS;
	int8_t m_iUSE_ON_UPDATE_CALLBACK;
	int8_t m_iVIEWPORT_FOCUS_BORDER;
	int8_t m_iBUG_CITYBAR_SPECIALISTS;
	int8_t m_iEVENT_PROBABILITY_ROLL_SIDES;
	int8_t m_iMAX_EVASION_PROBABILITY;
	int8_t m_iMIN_REVOLUTION_TURNS;
	int8_t m_iSCORE_HANDICAP_PERCENT_OFFSET;
	int8_t m_iUNIT_PRODUCTION_DECAY_PERCENT;
	int8_t m_iAMPHIB_ATTACK_MODIFIER;
	int8_t m_iESPIONAGE_SPENDING_MULTIPLIER;
	int32_t m_iGREATER_COMMERCE_SWITCH_POINT;
	int8_t m_iBATTLEFIELD_PROMOTIONS;
	int8_t m_iC2C_ROUGH_BOMBARD_VALUE_MODIFIER;
	int8_t m_iADVANCED_START_CULTURE_COST;
	int8_t m_iRELIGION_SPREAD_DISTANCE_DIVISOR;
	int8_t m_iROUTE_FEATURE_GROWTH_MODIFIER;
	int8_t m_iWE_LOVE_THE_KING_POPULATION_MIN_POPULATION;
	int8_t m_iBBAI_ATTACK_CITY_STACK_RATIO;
	int8_t m_iBBAI_DEFENSIVE_PACT_BEHAVIOR;
	int8_t m_iCONSCRIPT_ANGER_DIVISOR;
	int8_t m_iBASE_SPY_DESTROY_COST;
	int8_t m_iBUG_BUILDING_ADDITIONAL_FOOD_HOVER;
	int8_t m_iBUG_CITYBAR_HIDE_INSTRUCTIONS;
	int8_t m_iCURSOR_AIRBOMB;
	int8_t m_iINQUISITION_BUILDING_GOLD_DIVISOR;
	int8_t m_iWW_ATTACKED_WITH_NUKE;
	int8_t m_iADVANCED_START_CITY_COST_INCREASE;
	int8_t m_iBUILDING_PRODUCTION_DECAY_PERCENT;
	int8_t m_iRIVAL_TEAM_STARTING_MODIFIER;
	int16_t m_iBBAI_SKIP_BOMBARD_BASE_STACK_RATIO;
	int8_t m_iSTANDARD_HANDICAP_QUICK;
	int8_t m_iBUG_BUILDING_ADDITIONAL_GREAT_PEOPLE_HOVER;
	int8_t m_iCAN_TRADE_CONTACT;
	int8_t m_iCITY_HEAL_RATE;
	int8_t m_iESPIONAGE_INTERCEPT_COUNTERESPIONAGE_MISSION;
	int8_t m_iUSE_CANNOT_CONSTRUCT_CALLBACK;
	int8_t m_iALWAYS_USE_MAX_COMPAT_SAVES;
	int8_t m_iBARBARIAN_LEADER;
	int8_t m_iBUG_CITYBAR_BASE_VALUES;
	int8_t m_iUSE_ON_UNIT_SELECTED_CALLBACK;
	uint8_t m_iLAKE_PLOT_RAND;
	int8_t m_iNUM_LAKE_NAMES;
	int8_t m_iACO_SHOW_ATTACKER_HEALTH_BARS;
	int8_t m_iACO_SHOW_DEFENDER_INFO;
	int8_t m_iBATTLE_EFFECT_LESS_PRODUCTION;
	int8_t m_iFREE_TRADE_CORPORATION_SPREAD_MOD;
	int8_t m_iNUKE_POPULATION_DEATH_RAND_1;
	int8_t m_iNUKE_POPULATION_DEATH_RAND_2;
	int8_t m_iNO_ESPIONAGE_CULTURE_LEVEL_MODIFIER;
	int8_t m_iBUG_SPECIALIST_HOVER_ACTUAL_EFFECTS;
	int16_t m_iCORPORATION_SPREAD_RAND;
	int8_t m_iCURSOR_DEFAULT;
	int8_t m_iBUG_CITYBAR_STARVATION_TURNS;
	int8_t m_iCAN_TRADE_OPEN_BORDERS;
	int8_t m_iMAX_EXPERIENCE_AFTER_UPGRADE;
	int8_t m_iNUM_PEAK_NAMES;
	int8_t m_iTEST_GAMEFONTS;
	int8_t m_iACO_SHOW_UNHARMED_ODDS;
	int8_t m_iBUG_CITYBAR_FOOD_ASSIST;
	int8_t m_iCAN_TRADE_EMBARGO;
	int8_t m_iINITIAL_OUTSIDE_UNIT_GOLD_PERCENT;
	int8_t m_iSS_ASSASSINATE;
	int8_t m_iAIR_COMBAT_DAMAGE;
	int8_t m_iDCM_RANGE_BOMBARD;
	int8_t m_iDCM_RB_CITY_INACCURACY;
	int8_t m_iBBAI_VICTORY_STRATEGY_CULTURE;
	int8_t m_iCAN_TRADE_CITIES;
	int8_t m_iCAN_TRADE_CIVICS;
	int8_t m_iENABLE_DYNAMIC_UNIT_ENTITIES;
	int8_t m_iMAX_DISTANCE_CITY_MAINTENANCE;
	int8_t m_iCURSOR_AIRLIFT;
	int8_t m_iDCM_STACK_ATTACK;
	int8_t m_iFROZEN_TERRAIN;
	int8_t m_iMIN_CITY_RANGE;
	int8_t m_iTEMPERATE_FEATURE;
	int8_t m_iROUTES_UPGRADE;
	int8_t m_iAI_SHOULDNT_MANAGE_PLOT_ASSIGNMENT;
	int8_t m_iFEATURE_GROWTH_MODIFIER;
	int8_t m_iGREAT_PEOPLE_THRESHOLD;
	int8_t m_iINITIAL_CITY_POPULATION;
	int8_t m_iCIVILOPEDIA_SHOW_ACTIVE_CIVS_ONLY;
	int8_t m_iESPIONAGE_INTERCEPT_RECENT_MISSION;
	int8_t m_iSUPER_FORTS_DURATION_BEFORE_REVOLT;
	int8_t m_iBUG_CITYBAR_BUILDING_ACTUAL_EFFECTS;
	int8_t m_iESPIONAGE_CITY_HOLY_CITY_MOD;
	int8_t m_iVICTORY_SOUNDTRACK_AVAILABLE;
	int8_t m_iBARBARIAN_CIVILIZATION;
	int8_t m_iBASE_UNIT_UPGRADE_COST;
	int8_t m_iMAX_BUILDINGS_PER_CITY;
	uint8_t m_iBASE_SPY_SABOTAGE_COST;
	int8_t m_iBBAI_SKIP_BOMBARD_BEST_ATTACK_ODDS;
	int8_t m_iBUG_PLOT_HOVER_PARTIAL_BUILDS;
	int8_t m_iIDW_NO_NAVAL_INFLUENCE;
	int8_t m_iINITIAL_BASE_FREE_UNITS;
	int8_t m_iCURSOR_SIZEALL;
	int8_t m_iGLOBAL_WARMING_TERRAIN;
	int8_t m_iMAX_INTERCEPTION_PROBABILITY;
	int8_t m_iSTANDARD_HANDICAP;
	int8_t m_iACO_SHOW_ATTACKER_INFO;
	uint8_t m_iBBAI_TURTLE_ENEMY_POWER_RATIO;
	int8_t m_iCONSCRIPT_POPULATION_PER_COST;
	int8_t m_iGAMEFONT_TGA_RELIGIONS;
	int8_t m_iUSE_CAN_DO_PRODUCTION_CALLBACK;
	int8_t m_iBUILDING_PRODUCTION_PERCENT;
	int8_t m_iEVENT_MESSAGE_TIME_LONG;
	int8_t m_iMIN_INTERCEPTION_DAMAGE;
	int8_t m_iRIVER_RAND_ON_MORE_RIVERS;
	int8_t m_iSTANDARD_CALENDAR;
	int8_t m_iTEMPERATE_TERRAIN;
	int8_t m_iUSE_CAN_DO_GROWTH_CALLBACK;
	int8_t m_iACO_SHOW_UNROUNDED_EXPERIENCE;
	int8_t m_iCAPITAL_BUILDINGCLASS;
	int8_t m_iTECH_COST_FIRST_KNOWN_PREREQ_MODIFIER;
	int8_t m_iUNIT_PRODUCTION_PERCENT;
	int8_t m_iADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES;
	int8_t m_iBUG_CITYBAR_HURRY_ASSIST_INCLUDE_CURRENT;
	int8_t m_iCURSOR_GO_TO;
	int8_t m_iFORCED_WAR_WAR_WEARINESS_MODIFIER;
	int8_t m_iMIN_POP_CONSIDER_INQUISITORS;
	int8_t m_iNPC1_CIVILIZATION;
	int8_t m_iNPC2_CIVILIZATION;
	int8_t m_iNPC3_CIVILIZATION;
	int8_t m_iNPC4_CIVILIZATION;
	int8_t m_iNPC5_CIVILIZATION;
	int8_t m_iNPC6_CIVILIZATION;
	int8_t m_iNPC7_CIVILIZATION;
	int8_t m_iNPC8_CIVILIZATION;
	int8_t m_iRECON_VISIBILITY_RANGE;
	int8_t m_iCAN_TRADE_GOLD_PER_TURN;
	int8_t m_iDYNAMIC_CIV_NAMES;
	int8_t m_iLAKE_MAX_AREA_SIZE;
	int8_t m_iMIN_WATER_SIZE_FOR_OCEAN;
	int8_t m_iNUKE_POPULATION_DEATH_BASE;
	int8_t m_iNUKE_UNIT_DAMAGE_RAND_1;
	int8_t m_iNUKE_UNIT_DAMAGE_RAND_2;
	int8_t m_iPEAK_EXTRA_DEFENSE;
	int8_t m_iOCCUPATION_CULTURE_PERCENT_THRESHOLD;
	int8_t m_iBUG_BUILDING_SAVED_MAINTENANCE_HOVER;
	int8_t m_iBUG_PRODUCTION_DECAY_HOVER_BUILDING_THRESHOLD;
	int8_t m_iBUG_PRODUCTION_DECAY_HOVER_UNIT_THRESHOLD;
	int8_t m_iBUG_SPED_UP_TECHS_HOVER;
	int8_t m_iCIVIC_ANARCHY_QTY_DISCOUNT;
	int8_t m_iSAD_MAX_MODIFIER;
	int8_t m_iWW_DECAY_PEACE_PERCENT;
	int8_t m_iCAN_TRADE_WORKERS;
	int8_t m_iFIRST_EVENT_DELAY_TURNS;
	int8_t m_iMAX_CITY_DEFENSE_DAMAGE;
	int8_t m_iUSE_CANNOT_HANDLE_ACTION_CALLBACK;
	int8_t m_iACO_SWAP_VIEWS;
	uint8_t m_iBONUS_OBSOLETE_VALUE_MODIFIER;
	int8_t m_iBUG_CITYBAR_HAPPINESS;
	int8_t m_iBUG_CITY_SCREEN_BASE_COMMERCE_HOVER;
	int8_t m_iCITY_GROWTH_MULTIPLIER;
	int8_t m_iEXTRA_YIELD;
	int8_t m_iLAND_UNITS_CAN_ATTACK_WATER_CITIES;
	int8_t m_iPLOTS_PER_RIVER_EDGE_DIVISOR;
	int8_t m_iADVANCED_START_MAX_UNITS_PER_CITY;
	int16_t m_iRELIGION_PERCENT_ANGER;
	int8_t m_iUSE_AI_UPDATE_UNIT_CALLBACK;
	int8_t m_iESPIONAGE_DISTANCE_MULTIPLIER_MOD;
	int8_t m_iHIGH_TO_LOW_FIRST_TURN_CHECK;
	int8_t m_iZOOM_CITY_FOR_PRODUCTION_POPUP;
	int8_t m_iANIMAL_DAMAGE_PERCENT_AFTER_SUBDUE;
	int8_t m_iMAX_INTERCEPTION_DAMAGE;
	int8_t m_iOVERSEAS_TRADE_MODIFIER;
	int16_t m_iPAGE_IN_DIST_ROUTE;
	int8_t m_iUSE_GET_BUILDING_COST_MOD_CALLBACK;
	int8_t m_iBARBARIAN_MAX_XP_VALUE;
	int8_t m_iBBAI_AIR_COMBAT;
	int8_t m_iBBAI_BOMBARD_ATTACK_CITY_MAX_STACK_FRACTION;
	int8_t m_iBBAI_BOMBARD_ATTACK_STACK_FRACTION;
	int8_t m_iCAN_TRADE_PEACE;
	int8_t m_iUSE_IS_VICTORY_CALLBACK;
	int8_t m_iUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK;
	int16_t m_iBASE_SPY_STEAL_PLANS_COST;
	int8_t m_iMAXED_BUILDING_GOLD_PERCENT;
	int8_t m_iMULTIPLAYER_WAR_WEARINESS_MODIFIER;
	int16_t m_iTURN_LOG_MAX_HEIGHT;
	int8_t m_iWATER_POTENTIAL_CITY_WORK_FOR_AREA;
	int8_t m_iESPIONAGE_CITY_RELIGION_STATE_MOD;
	int8_t m_iESTABLISH_MODIFIER_PER_TURN;
	int8_t m_iHURRY_INFLATION_DECAY_RATE;
	int8_t m_iMAXED_UNIT_GOLD_PERCENT;
	int8_t m_iRUINS_IMPROVEMENT;
	int8_t m_iSCORE_HANDICAP_PERCENT_PER;
	int8_t m_iUSE_CANNOT_SPREAD_RELIGION_CALLBACK;
	int8_t m_iADVANCED_START_CITY_PLACEMENT_MAX_RANGE;
	int8_t m_iRIVER_SOURCE_MIN_RIVER_RANGE;
	int8_t m_iTECH_DIFFUSION_KNOWN_TEAM_MODIFIER;
	int8_t m_iADVANCED_START_VISIBILITY_COST_INCREASE;
	int8_t m_iCAPTURE_GOLD_MAX_TURNS;
	int8_t m_iCOMMERCE_ATTACKS_FADE_RATE;
	int8_t m_iGOlDEN_AGE_PERCENT_LESS_FOOD_FOR_GROWTH;
	int8_t m_iBASE_REVOLT_OCCUPATION_TURNS;
	int8_t m_iBUG_IGNORE_HARMLESS_BARBARIANS;
	int8_t m_iCURSOR_EDIT;
	int8_t m_iDRY_TERRAIN;
	int8_t m_iOWN_TEAM_STARTING_MODIFIER;
	int8_t m_iCAN_TRADE_DEFENSIVE_PACT;
	int8_t m_iESPIONAGE_CITY_POP_EACH_MOD;
	int8_t m_iIDW_NO_BARBARIAN_INFLUENCE;
	int8_t m_iNUM_JUNGLE_NAMES;
	int8_t m_iPASSIVE_ANIMAL_LEADER;
	int8_t m_iADVANCED_START_POPULATION_COST_INCREASE;
	int8_t m_iBUG_BUILDING_ADDITIONAL_PRODUCTION_HOVER;
	int8_t m_iOUR_POPULATION_TRADE_MODIFIER;
	int16_t m_iCOMBAT_DIE_SIDES;
	int8_t m_iFREE_TRADE_AGREEMENT_ESPIONAGE_MISSION_COST_MODIFIER;
	int8_t m_iINITIAL_STATE_RELIGION_HAPPINESS;
	int8_t m_iMAX_HIT_POINTS;
	int8_t m_iMAX_NATIONAL_WONDERS_PER_CITY;
	int8_t m_iPEAK_SEE_THROUGH_CHANGE;
	int8_t m_iTURN_LOG_MIN_HEIGHT;
	int8_t m_iBASE_REVOLT_FREE_UNITS;
	uint8_t m_iSIZE_MATTERS_MOST_MULTIPLIER;
	int8_t m_iUSE_CAN_MAINTAIN_PROCESS_CALLBACK;
	int8_t m_iWASTAGE_START_CONSUMPTION_PERCENT;
	int8_t m_iBUG_ASK_DECLARE_WAR_UNITS;
	int8_t m_iBUG_PLOT_HOVER_LAT_LONG;
	int8_t m_iGOLDEN_AGE_LENGTH;
	int8_t m_iMAXED_PROJECT_GOLD_PERCENT;
	int16_t m_iMAX_ANARCHY_TURNS;
	int8_t m_iMAX_PLOT_LIST_ROWS;
	int8_t m_iMIN_VERSION;
	int8_t m_iNUM_DESERT_NAMES;
	int8_t m_iSS_BRIBE;
	int8_t m_iBARBARIAN_SPAWN_MODIFIER;
	int8_t m_iCAN_TRADE_WAR;
	int8_t m_iCITY_AIR_UNIT_CAPACITY;
	int8_t m_iNEUTRAL_HEAL_RATE;
	int16_t m_iSCORE_POPULATION_FACTOR;
	int8_t m_iUSE_MODDERS_PLAYEROPTION_1;
	int8_t m_iUSE_MODDERS_PLAYEROPTION_2;
	int8_t m_iUSE_MODDERS_PLAYEROPTION_3;
	int8_t m_iBBAI_HUMAN_VASSAL_WAR_BUILD;
	int8_t m_iCURSOR_LINK;
	int8_t m_iCURSOR_PING;
	int8_t m_iESPIONAGE_SPY_INTERCEPT_MOD;
	int8_t m_iLANDMARK_ANGER_DIVISOR;
	int8_t m_iMAX_TRADE_ROUTES;
	int8_t m_iMAX_WITHDRAWAL_PROBABILITY;
	int8_t m_iNUM_FOREST_NAMES;
	int8_t m_iTAXATION_ANGER_ROUND_DOWN;
	int8_t m_iBBAI_UNIT_CAPTURE;
	int8_t m_iBUG_TECH_TRADE_DENIAL_HOVER;
	int8_t m_iCOMBAT_EXPERIENCE_IN_BORDERS_PERCENT;
	int16_t m_iCULTURE_PERCENT_ANGER;
	int8_t m_iDCM_AIR_BOMBING;
	int8_t m_iUSE_CAN_RAZE_CITY_CALLBACK;
	int8_t m_iAT_WAR_CULTURE_ANGER_MODIFIER;
	int8_t m_iBASE_WAR_WEARINESS_MULTIPLIER;
	int8_t m_iBATTLE_EFFECT_LESS_FOOD;
	int8_t m_iBUILDING_PRODUCTION_DECAY_TIME;
	int8_t m_iINITIAL_TRADE_ROUTES;
	int8_t m_iMAX_PLOT_LIST_SIZE;
	int8_t m_iRENDER_GLOBEVIEW_CLOUDS;
	int8_t m_iAI_WORKER_MAX_DISTANCE_FROM_CITY_OUT_BORDERS;
	int8_t m_iUNIT_PRODUCTION_DECAY_TIME;
	int8_t m_iBUG_CITYBAR_TRADE_DETAIL;
	int8_t m_iCURSOR_GRIP;
	int8_t m_iCURSOR_REBASE;
	int8_t m_iDEFAULT_ANIM_PAGE_MAX;
	int8_t m_iDIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT;
	int8_t m_iMARSH_TERRAIN;
	int8_t m_iMOVE_DENOMINATOR;
	int8_t m_iWATER_IMPROVEMENT;
	int8_t m_iACO_SHOW_AVERAGE_HEALTH;
	int8_t m_iBUG_BUILDING_HOVER_ACTUAL_EFFECTS;
	int8_t m_iCORPORATION_SPREAD_DISTANCE_DIVISOR;
	int8_t m_iCURSOR_NUKE;
	int8_t m_iFREE_CITY_CULTURE;
	int8_t m_iGLOBAL_WARMING_POWER_WEIGHT;
	int32_t m_iMAX_DESIRED_MEMORY_USED;
	int8_t m_iPLAYER_ALWAYS_RAZES_CITIES;
	int8_t m_iSEAWATER_SEE_THROUGH_CHANGE;
	int8_t m_iSS_ENABLED;
	int8_t m_iSTANDARD_SEALEVEL;
	int16_t m_iTURN_LOG_MAX_WIDTH;
	int8_t m_iWAR_SUCCESS_NUKE;
	int8_t m_iACO_SHOW_SURVIVAL_ODDS;
	int8_t m_iBUG_LEADERHEAD_HOVER_WORST_ENEMY;
	int8_t m_iCAPTURE_GOLD_PER_POPULATION;
	int8_t m_iEMBASSY_ESPIONAGE_MISSION_COST_MODIFIER;
	int16_t m_iRAND_CORPORATION_BEST_SPREAD;
	int8_t m_iBUG_BUILDING_ADDITIONAL_HAPPINESS_HOVER;
	int8_t m_iCOLLATERAL_COMBAT_DAMAGE;
	int8_t m_iSAFE_GOLD_PERCENT;
	int16_t m_iSCORE_TECH_FACTOR;
	int8_t m_iUSE_CAN_CREATE_PROJECT_CALLBACK;
	int8_t m_iGLOBAL_WARMING_NUKE_WEIGHT;
	int8_t m_iIDW_EMERGENCY_DRAFT_MIN_POPULATION;
	int8_t m_iINTERCEPTION_MAX_ROUNDS;
	uint8_t m_iBBAI_SKIP_BOMBARD_MIN_STACK_RATIO;
	int8_t m_iCURSOR_MOVE;
	int8_t m_iENABLE_VIEWPORTS;
	int8_t m_iESPIONAGE_INTERCEPT_SPENDING_MAX;
	int8_t m_iUSE_AI_BESTTECH_CALLBACK;
	int8_t m_iWEEKS_PER_MONTHS;
	int8_t m_iCAN_TRADE_LIMITED_BORDERS;
	int8_t m_iMAX_AIRLIFT_RANGE;
	int8_t m_iMAX_NATIONAL_WONDERS_PER_CITY_FOR_OCC;
	int8_t m_iNUM_ROUTE_PREREQ_OR_BONUSES;
	int16_t m_iSCORE_LAND_FACTOR;
	int8_t m_iUSE_CAN_DECLARE_WAR_CALLBACK;
	int8_t m_iUSE_CAN_DO_GOLD_CALLBACK;
	int8_t m_iBUG_LEADERHEAD_HOVER_DEFENSIVE_PACTS;
	int8_t m_iMAX_NUM_LANGUAGES;
	int8_t m_iSTANDARD_CLIMATE;
	int8_t m_iUSE_CAN_DO_CULTURE_CALLBACK;
	int8_t m_iBBAI_VICTORY_STRATEGY_SPACE;
	int8_t m_iTRADE_PROFIT_PERCENT;
	int8_t m_iBUG_PRODUCTION_DECAY_HOVER;
	int8_t m_iINITIAL_CITY_ROUTE_TYPE;
	int8_t m_iWAR_SUCCESS_ATTACKING;
	int8_t m_iWAR_SUCCESS_DEFENDING;
	int8_t m_iWW_CAPTURED_CITY;
	int8_t m_iBASE_GOLDEN_AGE_UNITS;
	int8_t m_iCHOOSE_RELIGION;
	int8_t m_iNUM_CORPORATION_PREREQ_BONUSES;
	int16_t m_iSIZE_MATTERS_MOST_VOLUMETRIC_MULTIPLIER;
	int8_t m_iUSE_CAN_DO_GREATPEOPLE_CALLBACK;
	int8_t m_iUSE_EXTRA_PLAYER_COSTS_CALLBACK;
	int8_t m_iVASSAL_REVOLT_MASTER_LOSSES_FACTOR;
	int8_t m_iADVANCED_START_CULTURE_COST_INCREASE;
	int8_t m_iUSE_GET_UNIT_COST_MOD_CALLBACK;
	int8_t m_iBUG_BUILDING_ADDITIONAL_COMMERCE_HOVER;
	int8_t m_iCITY_MAX_NUM_BUILDINGS;
	int8_t m_iUNIT_PRODUCTION_PERCENT_SM;
	int8_t m_iUSE_UPGRADE_UNIT_PRICE_CALLBACK;
	int8_t m_iVASSAL_HAPPINESS;
	int8_t m_iBUG_PRECHOP_IMPROVEMENTS;
	int8_t m_iCURSOR_AIRSTRIKE;
	int8_t m_iGOLDEN_AGE_GREAT_PEOPLE_MODIFIER;
	int8_t m_iIGNORE_PLOT_GROUP_FOR_TRADE_ROUTES;
	int8_t m_iMIN_CITY_ATTACK_MODIFIER_FOR_SIEGE_TOWER;
	int8_t m_iBUG_BUILDING_ADDITIONAL_DEFENSE_HOVER;
	int8_t m_iCITY_SCREEN_CLICK_WILL_EXIT;
	int8_t m_iOC_RESPAWN_HOLY_CITIES;
	int8_t m_iOWNERSHIP_SCORE_DURATION_THRESHOLD;
	int8_t m_iREVOLT_TOTAL_CULTURE_MODIFIER;
	int8_t m_iACO_MERGE_SHORT_BARS;
	int8_t m_iINITIAL_FREE_OUTSIDE_UNITS;
	int8_t m_iNUM_BAY_NAMES;
	int8_t m_iPEAK_SEE_FROM_CHANGE;
	int8_t m_iSPY_DESTROY_COST_MULTIPLIER_LIMITED;
	int8_t m_iWW_DECAY_RATE;
	int8_t m_iWW_HIT_BY_NUKE;
	int8_t m_iDIPLO_VOTE_SECRETARY_GENERAL_INTERVAL;
	int8_t m_iHILLS_EXTRA_MOVEMENT;
	int8_t m_iKILLERRABBIT_SPAWN_MODIFIER;
	int8_t m_iRAZING_CULTURAL_PERCENT_THRESHOLD;
	int8_t m_iWW_CAPTURED_UNIT;
	int8_t m_iACO_SHOW_DEFENSE_MODIFIERS;
	int8_t m_iBASE_CITY_GROWTH_THRESHOLD;
	int8_t m_iCURSOR_BUSY;
	int8_t m_iESPIONAGE_INTERCEPT_COUNTERSPY;
	int8_t m_iESPIONAGE_SPY_MISSION_ESCAPE_MOD;
	int8_t m_iGLOBAL_WARMING_BONUS_WEIGHT;
	int8_t m_iGLOBAL_WARMING_UNHEALTH_WEIGHT;
	int8_t m_iINFILTRATE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT;
	int8_t m_iINITIAL_AI_CITY_PRODUCTION;
	int8_t m_iUSE_AI_DO_DIPLO_CALLBACK;
	int8_t m_iUSE_CAN_RESEARCH_CALLBACK;
	int8_t m_iBUG_CITYBAR_AIRPORT_ICONS;
	int8_t m_iENEMY_HEAL_RATE;
	int8_t m_iFREE_CITY_ADJACENT_CULTURE;
	int8_t m_iGREAT_PEOPLE_THRESHOLD_INCREASE_TEAM;
	int8_t m_iIDW_INFLUENCE_RADIUS;
	int16_t m_iPERCENT_ANGER_DIVISOR;
	int8_t m_iRENDER_AREABORDER_UNDER_FEATURES;
	int8_t m_iTECH_COST_TOTAL_KNOWN_TEAM_MODIFIER;
	int8_t m_iWAR_SUCCESS_CITY_CAPTURING;
	int8_t m_iBUG_CITYBAR_CULTURE_TURNS;
	int8_t m_iMINIMUM_MOUNTAIN_RANGE_SIZE;
	int8_t m_iOCCUPATION_TURNS_POPULATION_PERCENT;
	int8_t m_iPAGE_IN_DIST_CITY;
	int8_t m_iTEAM_VOTE_MIN_CANDIDATES;
	int8_t m_iUSE_AI_CHOOSE_PRODUCTION_CALLBACK;
	int8_t m_iMIN_TIMER_UNIT_DOUBLE_MOVES;
	int8_t m_iPROJECT_PRODUCTION_PERCENT;
	int8_t m_iBUG_CONSCRIPT_LIMIT_HOVER;
	int8_t m_iGLOBAL_WARMING_FOREST;
	int8_t m_iMAX_FORTIFY_TURNS;
	int8_t m_iWW_UNIT_CAPTURED;
	int8_t m_iADVANCED_START_SIGHT_RANGE;
	int8_t m_iBBAI_VICTORY_STRATEGY_DOMINATION;
	int8_t m_iDISBANDING_EARNS_GOLD;
	int8_t m_iTECH_DIFFUSION_WELFARE_THRESHOLD;
	int8_t m_iUSE_CAN_DO_RESEARCH_CALLBACK;
	int8_t m_iBBAI_VICTORY_STRATEGY_DIPLOMACY;
	int8_t m_iBUG_CITYBAR_GREAT_PERSON_TURNS;
	int8_t m_iMIN_BARBARIAN_STARTING_DISTANCE;
	int8_t m_iSEAWATER_SEE_FROM_CHANGE;
	int8_t m_iUPSCALED_RESEARCH_COST_MODIFIER;
	int8_t m_iUSE_CAN_DO_RELIGION_CALLBACK;
	int8_t m_iCITY_BARBARIAN_DEFENSE_MODIFIER;
	int8_t m_iMAX_WORLD_WONDERS_PER_CITY;
	int8_t m_iPAGE_IN_DIST_UNIT;
	int8_t m_iSTANDARD_ERA;
	int8_t m_iBASE_CAPTURE_GOLD;
	int8_t m_iHILLS_SEE_FROM_CHANGE;
	int8_t m_iLAND_IMPROVEMENT;
	int8_t m_iMAX_BATTLE_TURNS;
	int8_t m_iSHOW_HIDDEN_ATTITUDE;
	int8_t m_iWAR_SUCCESS_UNIT_CAPTURING;
	int8_t m_iBASE_OCCUPATION_TURNS;
	int8_t m_iGREAT_GENERALS_THRESHOLD_INCREASE_TEAM;
	int8_t m_iBUG_CONSCRIPT_UNIT_HOVER;
	int8_t m_iCURSOR_SIZENE;
	int8_t m_iESPIONAGE_CULTURE_MULTIPLIER_MOD;
	int8_t m_iESPIONAGE_SPY_REVEAL_IDENTITY_PERCENT;
	int8_t m_iGREAT_PEOPLE_THRESHOLD_INCREASE;
	int8_t m_iIDW_PILLAGE_INFLUENCE_ENABLED;
	int8_t m_iINITIAL_BASE_FREE_MILITARY_UNITS;
	int8_t m_iINITIAL_GOLD_PER_UNIT;
	int8_t m_iNUKE_BUILDING_DESTRUCTION_PROB;
	int8_t m_iNUKE_FALLOUT_PROB;
	int8_t m_iNUM_AND_TECH_PREREQS;
	int8_t m_iREVOLT_TEST_PROB;
	int8_t m_iUSE_CANNOT_FOUND_CITY_CALLBACK;
	int8_t m_iBARBARIAN_HANDICAP;
	int8_t m_iBATTLE_EFFECT_LESS_COMMERCE;
	int8_t m_iBBAI_HUMAN_AS_VASSAL_OPTION;
	int8_t m_iBUG_BONUS_TRADE_DENIAL_HOVER;
	int16_t m_iRELIGION_SPREAD_RAND;
	int8_t m_iCOLD_FEATURE;
	int8_t m_iHILLS_SEE_THROUGH_CHANGE;
	int16_t m_iHOLYCITY_REMOVAL_GOLD;
	int16_t m_iOC_MIN_REV_INDEX;
	int8_t m_iUSE_CAN_DO_CIVIC_CALLBACK;
	int8_t m_iUSE_FINISH_TEXT_CALLBACK;
	int8_t m_iUSE_SPIES_NO_ENTER_BORDERS;
	int8_t m_iACO_IGNORE_BARB_FREE_WINS;
	int8_t m_iAGGRESSIVE_ANIMAL_LEADER;
	int8_t m_iBUG_CITYBAR_HURRY_ASSIST;
	int8_t m_iCAN_TRADE_EMBASSIES;
	int8_t m_iFREE_VASSAL_POPULATION_PERCENT;
	int8_t m_iUSE_CAN_BUILD_CALLBACK;
	int8_t m_iSCORE_VICTORY_PERCENT;
	int8_t m_iUSE_IS_PLAYER_RESEARCH_CALLBACK;
	int8_t m_iDIPLOMACY_VALUE_REMAINDER;
	int8_t m_iBUG_CITYBAR_HEALTH;
	int8_t m_iDEFY_RESOLUTION_POP_ANGER;
	int8_t m_iMAX_BOMBARD_DEFENSE;
	int8_t m_iMAX_YIELD_STACK;
	int8_t m_iGREAT_GENERALS_THRESHOLD;
	int8_t m_iLAND_TERRAIN;
	int8_t m_iCITY_FREE_CULTURE_GROWTH_FACTOR;
	int8_t m_iCITY_THIRD_RING_EXTRA_GROWTH_THRESHOLD_PERCENT;
	int8_t m_iBASE_FEATURE_PRODUCTION_PERCENT;
	int8_t m_iBUG_LEADERHEAD_HOVER_HIDDEN_ATTITUDE;
	int8_t m_iCOLD_TERRAIN;
	int8_t m_iCURSOR_PARADROP;
	int8_t m_iDCM_FIGHTER_ENGAGE;
	int8_t m_iFORCE_UNOWNED_CITY_TIMER;
	int8_t m_iRANGE_COMBAT_DAMAGE;
	int8_t m_iBUG_CDA_ZOOM_CITY_DETAILS;
	int8_t m_iBUG_HURRY_OVERFLOW_HOVER;
	int8_t m_iACO_DEBUG;
	int8_t m_iCONSCRIPT_POP_ANGER;
	int8_t m_iFREE_VASSAL_LAND_PERCENT;
	int8_t m_iHILLS_EXTRA_DEFENSE;
	int8_t m_iUNIT_GOLD_DISBAND_DIVISOR;
	int8_t m_iUSE_AI_CAN_DO_WARPLANS_CALLBACK;
	int8_t m_iXML_LOGGING_ENABLED;
	int8_t m_iPEAK_BUILD_TIME_MODIFIER;
	int8_t m_iUPKEEP_POPULATION_OFFSET;
	int16_t m_iCIV4_VERSION;
	int8_t m_iTECH_COST_KNOWN_PREREQ_MODIFIER;
	int8_t m_iBBAI_VICTORY_STRATEGY_CONQUEST;
	int8_t m_iBUG_UPDATE_UNIT_NAME_ON_UPGRADE;
	int8_t m_iDCM_ARCHER_BOMBARD;
	int8_t m_iFOREIGN_TRADE_FULL_CREDIT_PEACE_TURNS;
	int16_t m_iNO_MILITARY_PERCENT_ANGER;
	int8_t m_iUSE_GET_CITY_FOUND_VALUE_CALLBACK;
	int8_t m_iACO_SHOW_TOTAL_DEFENSE_MODIFIER;
	int8_t m_iBUG_CITYBAR_REVOLT_CHANCE;
	int8_t m_iBUG_UNIT_EXPERIENCE_HOVER;
	int8_t m_iEXPERIENCE_FROM_WITHDRAWL;
	int8_t m_iUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK;
	int8_t m_iACO_SHOW_MODIFIER_LABELS;
	int8_t m_iAGGRESSIVE_ANIMAL_CIVILIZATION;
	int8_t m_iMIN_EXPERIENCE_PER_COMBAT;
	int8_t m_iNUKE_FEATURE;
	int8_t m_iBUG_GREAT_PEOPLE_RATE_BREAKDOWN_HOVER;
	int8_t m_iCAN_TRADE_RELIGIONS;
	int8_t m_iADVANCED_START_POPULATION_COST;
	int8_t m_iCUT_LOSERS_TURN_INCREMENT;
	int8_t m_iNUKE_NON_COMBAT_DEATH_THRESHOLD;
	int8_t m_iADVANCED_START_VISIBILITY_COST;
	int8_t m_iBUG_PRECHOP_FORESTS;
	int8_t m_iINITIAL_FREE_MILITARY_UNITS_POPULATION_PERCENT;
	int8_t m_iUSE_CANNOT_TRAIN_CALLBACK;
	int8_t m_iFRESH_WATER_HEALTH_CHANGE;
	int8_t m_iRENDER_WATER;
	int8_t m_iWARM_FEATURE;
	int8_t m_iBONUS_COUNT_PERCENTAGE_MODIFIER_ON_MORE_RESOURCES;
	int8_t m_iNUM_BUILDING_PREREQ_OR_BONUSES;
	int8_t m_iOUR_POPULATION_TRADE_MODIFIER_OFFSET;
	int8_t m_iREVOLT_OCCUPATION_TURNS_PERCENT;
	int8_t m_iTECH_DIFFUSION_WELFARE_MODIFIER;
	int8_t m_iCAPTURE_GOLD_RAND1;
	int8_t m_iCAPTURE_GOLD_RAND2;
	int8_t m_iCOLONY_NUM_FREE_DEFENDERS;
	int8_t m_iSTANDARD_GAMESPEED;
	int8_t m_iTHEIR_POPULATION_TRADE_PERCENT;
	int8_t m_iEVENT_MESSAGE_TIME;
	int8_t m_iSEA_ANIMAL_SPAWN_MODIFIER;
	int8_t m_iESPIONAGE_CITY_TRADE_ROUTE_MOD;
	int8_t m_iINITIAL_NON_STATE_RELIGION_HAPPINESS;
	int16_t m_iUPGRADE_ROUND_LIMIT;
	int8_t m_iVASSAL_REVOLT_OWN_LOSSES_FACTOR;
	int8_t m_iDCM_OPP_FIRE;
	int8_t m_iSCORE_FREE_PERCENT;
	int8_t m_iCAN_TRADE_RESOURCES;
	int8_t m_iMAX_EXPERIENCE_PER_COMBAT;
	int8_t m_iWW_KILLED_UNIT_DEFENDING;
	int8_t m_iBUG_BUILDING_ADDITIONAL_HEALTH_HOVER;
	int8_t m_iESPIONAGE_EACH_TURN_UNIT_COST_DECREASE;
	int8_t m_iACO_SHOW_EXPERIENCE_RANGE;
	int8_t m_iGREAT_WORKS_CULTURE_TURNS;
	int8_t m_iSPY_STEAL_PLANS_COST_MULTIPLIER;
	int8_t m_iNUM_UNIT_AND_TECH_PREREQS;
	int8_t m_iSTARTING_DISTANCE_PERCENT;
	int8_t m_iTREEHUGGER_DEFENSE_BONUS;
	int8_t m_iDEEP_WATER_TERRAIN;
	uint8_t m_iCORPORATION_FOREIGN_SPREAD_COST_PERCENT;
	int8_t m_iFORTIFY_MODIFIER_PER_TURN;
	int8_t m_iPEACE_TREATY_LENGTH;
	int8_t m_iWW_UNIT_KILLED_DEFENDING;
	int8_t m_iNUM_OR_TECH_PREREQS;
	int8_t m_iSHIP_BLOCKADE_RANGE;
	int8_t m_iBUG_PRODUCTION_POPUP_TRAIN_MILITARY_UNITS_FOREVER;
	int8_t m_iDCM_BATTLE_EFFECTS;
	int8_t m_iESCAPE_MODIFIER_PER_TURN;
	int16_t m_iPATH_DAMAGE_WEIGHT;
	int8_t m_iDEFAULT_SPECIALIST;
	int8_t m_iCOMBAT_DAMAGE;
	int8_t m_iCURSOR_RECON;
	int8_t m_iFOUND_RELIGION_CITY_RAND;
	int8_t m_iHURRY_POP_ANGER;
	int8_t m_iMIN_CIV_STARTING_DISTANCE;
	int8_t m_iNEW_HURRY_MODIFIER;
	int16_t m_iSAVE_VERSION;
	int8_t m_iBUG_SENTRY_HEALING_ONLY_NEUTRAL;
	int8_t m_iINITIAL_FREE_UNITS_POPULATION_PERCENT;
	int16_t m_iTECH_COST_MODIFIER;
	int8_t m_iBATTLE_EFFECTS_MINIMUM_TURN_INCREMENTS;
	int8_t m_iUSE_ON_UNIT_LOST_CALLBACK;
	int8_t m_iCANNOT_CLAIM_OCEAN;
	int8_t m_iFOOD_CONSUMPTION_PER_POPULATION;
	int8_t m_iNEANDERTHAL_SPAWN_MODIFIER;
	int8_t m_iDCM_ACTIVE_DEFENSE;
	int8_t m_iBUG_PRODUCTION_POPUP_TRAIN_CIVILIAN_UNITS_FOREVER;
	int8_t m_iTECH_COST_EXTRA_TEAM_MEMBER_MODIFIER;
	int8_t m_iBUG_SENTRY_HEALING;
	int8_t m_iDIRTY_POWER_HEALTH_CHANGE;
	int8_t m_iHURRY_ANGER_DIVISOR;
	int8_t m_iNO_MILITARY_UNIT_TRADING;
	int8_t m_iSTANDARD_TURNTIMER;
	int8_t m_iWW_KILLED_UNIT_ATTACKING;
	int8_t m_iFEATURE_PRODUCTION_PERCENT_MULTIPLIER;
	int8_t m_iANIMAL_MAX_XP_VALUE;
	int8_t m_iDCM_RB_CITYBOMBARD_CHANCE;
	int8_t m_iUSE_CANNOT_MAINTAIN_PROCESS_CALLBACK;
	int8_t m_iBASE_RESEARCH_RATE;
	int8_t m_iCAMERA_FORCE_TO_SMALLEST_MAX_DISTANCE;
	int8_t m_iDCM_ATTACK_SUPPORT;
	int8_t m_iFRIENDLY_HEAL_RATE;
	int8_t m_iMAX_UNIT_VISIBILITY_RANGE;
	int8_t m_iCURSOR_SIZEH;
	int8_t m_iESPIONAGE_MISSION_COST_END_TOTAL_PERCENT_ADJUSTMENT;
	int8_t m_iPASSIVE_ANIMAL_CIVILIZATION;
	int8_t m_iREVOLT_DEFENSE_STATE_RELIGION_MODIFIER;
	int8_t m_iREVOLT_OFFENSE_STATE_RELIGION_MODIFIER;
	int8_t m_iUPKEEP_CITY_OFFSET;
	int8_t m_iBUG_CITYBAR_BUILDING_ICONS;
	int8_t m_iGAMEFONT_TGA_CORPORATIONS;
	int8_t m_iMINIMUM_JUNGLE_SIZE;
	int8_t m_iWW_UNIT_KILLED_ATTACKING;
	int8_t m_iCIRCUMNAVIGATE_FREE_MOVES;
	uint8_t m_iMAX_PAGING_FRAME_TIME_MS;
	int8_t m_iREVOLT_FREE_UNITS_PERCENT;
	int8_t m_iESPIONAGE_SPY_NO_INTRUDE_INTERCEPT_MOD;
	int8_t m_iGLOBAL_WARMING_PROB;
	int8_t m_iIDW_EMERGENCY_DRAFT_ENABLED;
	int8_t m_iNUCLEAR_WINTER_PROB;
	int16_t m_iMINIMAP_RENDER_SIZE;
	int16_t m_iSCORE_WONDER_FACTOR;
	int8_t m_iADVANCED_START_CITY_COST;
	int8_t m_iMINIMUM_DESERT_SIZE;
	int8_t m_iHOLY_CITY_INFLUENCE;
	int8_t m_iUSE_CAN_DO_COMBAT_CALLBACK;
	int8_t m_iACO_SHOW_BASIC_INFO;
	int8_t m_iMINIMUM_FOREST_SIZE;
	int8_t m_iNUM_MOUNTAINS_NAMES;
	int8_t m_iNUM_WARNING_REVOLTS;
	int16_t m_iPAGE_IN_DIST_RIVER;
	int8_t m_iRANGED_ATTACKS_USE_MOVES;
	int8_t m_iBARBARIAN_FREE_TECH_PERCENT;
	int8_t m_iBUG_CITYBAR_BASE_PRODUCTION;
	int8_t m_iMAX_TEAM_WONDERS_PER_CITY;
	uint8_t m_iMORE_XP_TO_LEVEL_MODIFIER;
	int8_t m_iPOWER_HEALTH_CHANGE;
	int8_t m_iBUG_CITYBAR_COMMERCE;
	int8_t m_iUSE_CAN_CONSTRUCT_CALLBACK;
	int8_t m_iCURSOR_ROUTE_TO;
	int8_t m_iCURSOR_SIZEV;
	int8_t m_iRIVER_SOURCE_MIN_SEAWATER_RANGE;
	int8_t m_iUNIT_ANIM_PAGE_MAX;
	int8_t m_iWORKER_TRADE_VALUE_PERCENT_ADJUSTMENT;
	int8_t m_iMIN_BARBARIAN_CITY_STARTING_DISTANCE;
	int8_t m_iVIEWPORT_SIZE_X;
	int8_t m_iEVENT_MESSAGE_STAGGER_TIME;
	int8_t m_iFOUND_CORPORATION_CITY_RAND;
	int8_t m_iPEAK_EXTRA_MOVEMENT;
	int8_t m_iVIEWPORT_SIZE_Y;
	float m_fIDW_FORT_CAPTURE_MULTIPLIER;
	float m_fGAME_CITY_SIZE_LINMAP_AT_0;
	float m_fGAME_CITY_SIZE_LINMAP_AT_50;
	float m_fFLAG_OFFSET2_X;
	float m_fUNIT_TRAIL_RESOLUTION;
	float m_fFLAG_OFFSET2_Y;
	float m_fCAMERA_START_DISTANCE;
	float m_fCAMERA_SMALLEST_MAX_DISTANCE;
	float m_fIDW_EMERGENCY_DRAFT_STRENGTH;
	float m_fGAME_CITY_SIZE_EXP_MODIFIER;
	float m_fCAMERA_MIN_YAW;
	float m_fCAMERA_MAX_YAW;
	float m_fFOW_MINIMAP_WAS_VISIBLE_COLOR;
	float m_fBONUS_SCALE;
	float m_fIDW_WARLORD_MULTIPLIER;
	float m_fCAMERA_CITY_ZOOM_IN_DISTANCE;
	float m_fCAMERA_MIN_DISTANCE;
	float m_fCAMERA_MAX_SCROLL_SPEED;
	float m_fPLOT_SIZE;
	float m_fIMPROVEMENT_SCALE;
	float m_fAIR_DEFEND_FINISH;
	float m_fCAMERA_MAX_TURN_OFFSET;
	float m_fCAMERA_MIN_SCROLL_SPEED;
	float m_fCAMERA_NEAR_FAR_PLANE_RATIO;
	float m_fAIR_PATROL_RADIUS;
	float m_fCAMERA_MAX_TRAVEL_DISTANCE;
	float m_fAIR_IDLE_HEIGHT;
	float m_fAIR_PATROL_HEIGHT;
	float m_fIDW_BASE_PILLAGE_INFLUENCE;
	float m_fFIELD_OF_VIEW;
	float m_fAIR_BOMB_HEIGHT;
	float m_fFLAG_OFFSET_X;
	float m_fFLAG_OFFSET_Y;
	float m_fHEALTH_BAR_WIDTH;
	float m_fAIR_PATROL_SPEED;
	float m_fSINGLE_UNIT_GFX_EXTRA_SCALE;
	float m_fIDW_WINNER_PLOT_MULTIPLIER;
	float m_fCAMERA_SPECIAL_PITCH;
	float m_fGAME_CITY_SIZE_MAX_PERCENT_UNIQUE;
	float m_fIDW_EXPERIENCE_FACTOR;
	float m_fFOW_WAS_VISIBLE_COLOR;
	float m_fSAD_FACTOR_1;
	float m_fSAD_FACTOR_2;
	float m_fCAMERA_SHRINE_ZOOM_IN_DISTANCE;
	float m_fSAD_FACTOR_3;
	float m_fCAMERA_CITY_TURN;
	float m_fSAD_FACTOR_4;
	float m_fCAMERA_BATTLE_ZOOM_IN_DISTANCE;
	float m_fSHADOW_SCALE;
	float m_fWASTAGE_GROWTH_FACTOR;
	float m_fIDW_CITY_TILE_MULTIPLIER;
	float m_fAIR_EXECUTE_FINISH;
	float m_fIDW_PLOT_DISTANCE_FACTOR;
	float m_fEFFECT_DEFAULT_SIZE;
	float m_fIDW_BASE_COMBAT_INFLUENCE;
	float m_fIDW_NO_CITY_DEFENDER_MULTIPLIER;
	float m_fCAMERA_FAR_CLIP_Z_HEIGHT;
	float m_fAIR_DEFEND_DISTANCE;
	float m_fIDW_EMERGENCY_DRAFT_ANGER_MULTIPLIER;
	float m_fRIVER_Z_BIAS;
	float m_fCAMERA_LOWER_PITCH;
	float m_fCAMERA_UPPER_PITCH;
	float m_fROUTE_Z_BIAS;
	float m_fIDW_LOSER_PLOT_MULTIPLIER;
	float m_fAIR_EXECUTE_DISTANCE;
	float m_fUNIT_MULTISELECT_DISTANCE;
	const char* m_szGAME_CITY_SIZE_METHOD;
	const char* m_szC2C_VERSION;
	const char* m_szLEADERHEAD_RANDOM;
	const char* m_szLANGUAGE;
	const char* m_szPROFILER_ALTERNATE_SAMPLE_SET_SOURCE;
	const char* m_szQUICKSAVE;
	bool m_bENABLE_BACKGROUND_PROFILING;
	bool m_bDONT_ESCORT_SUBDUED_SEA_ANIMAL;
	bool m_bDYNAMIC_GREAT_WALL;
	bool m_bDONT_ESCORT_SUBDUED_LAND_ANIMAL;
};
#endif

#define DEF_ANIMAL_SPAWN_MODIFIER GC.getGameDefines().getANIMAL_SPAWN_MODIFIER()
#define DEF_C2C_MIN_PROP_CONTROL GC.getGameDefines().getC2C_MIN_PROP_CONTROL()
#define DEF_CURSOR_SPLITH GC.getGameDefines().getCURSOR_SPLITH()
#define DEF_USE_CANNOT_RESEARCH_CALLBACK GC.getGameDefines().getUSE_CANNOT_RESEARCH_CALLBACK()
#define DEF_MINIMUM_PLAYERS_WITH_TECH_FOR_AUTO_CORPORATION_FOUNDING GC.getGameDefines().getMINIMUM_PLAYERS_WITH_TECH_FOR_AUTO_CORPORATION_FOUNDING()
#define DEF_NUKE_UNIT_DAMAGE_BASE GC.getGameDefines().getNUKE_UNIT_DAMAGE_BASE()
#define DEF_RIVER_ATTACK_MODIFIER GC.getGameDefines().getRIVER_ATTACK_MODIFIER()
#define DEF_RIVER_EXTRA_MOVEMENT GC.getGameDefines().getRIVER_EXTRA_MOVEMENT()
#define DEF_BUG_HURRY_OVERFLOW_HOVER_INCLUDE_CURRENT GC.getGameDefines().getBUG_HURRY_OVERFLOW_HOVER_INCLUDE_CURRENT()
#define DEF_CORPORATION_FOUND_CHECK_TURNS GC.getGameDefines().getCORPORATION_FOUND_CHECK_TURNS()
#define DEF_BUG_CITYBAR_DRAFT_ANGER GC.getGameDefines().getBUG_CITYBAR_DRAFT_ANGER()
#define DEF_BUG_CITY_SCREEN_REMOVE_SPECIALIST_HOVER GC.getGameDefines().getBUG_CITY_SCREEN_REMOVE_SPECIALIST_HOVER()
#define DEF_MIN_CONVERSION_TURNS GC.getGameDefines().getMIN_CONVERSION_TURNS()
#define DEF_MIN_ANIMAL_STARTING_DISTANCE GC.getGameDefines().getMIN_ANIMAL_STARTING_DISTANCE()
#define DEF_RELIGION_REMOVAL_GOLD GC.getGameDefines().getRELIGION_REMOVAL_GOLD()
#define DEF_TECH_DIFFUSION_ENABLE GC.getGameDefines().getTECH_DIFFUSION_ENABLE()
#define DEF_USE_ON_UNIT_SET_XY_CALLBACK GC.getGameDefines().getUSE_ON_UNIT_SET_XY_CALLBACK()
#define DEF_TEMP_HAPPY GC.getGameDefines().getTEMP_HAPPY()
#define DEF_ACO_SHOW_SHIFT_INSTRUCTIONS GC.getGameDefines().getACO_SHOW_SHIFT_INSTRUCTIONS()
#define DEF_USE_CANNOT_DO_CIVIC_CALLBACK GC.getGameDefines().getUSE_CANNOT_DO_CIVIC_CALLBACK()
#define DEF_USE_CAN_DO_MELTDOWN_CALLBACK GC.getGameDefines().getUSE_CAN_DO_MELTDOWN_CALLBACK()
#define DEF_AI_CAN_DISBAND_UNITS GC.getGameDefines().getAI_CAN_DISBAND_UNITS()
#define DEF_PLOTS_PER_RIVER_EDGE GC.getGameDefines().getPLOTS_PER_RIVER_EDGE()
#define DEF_UNIT_VISIBILITY_RANGE GC.getGameDefines().getUNIT_VISIBILITY_RANGE()
#define DEF_PLOT_VISIBILITY_RANGE GC.getGameDefines().getPLOT_VISIBILITY_RANGE()
#define DEF_SHALLOW_WATER_TERRAIN GC.getGameDefines().getSHALLOW_WATER_TERRAIN()
#define DEF_SHOW_BUILDINGS_LEVEL GC.getGameDefines().getSHOW_BUILDINGS_LEVEL()
#define DEF_CAMERA_CITY_NO_PITCH GC.getGameDefines().getCAMERA_CITY_NO_PITCH()
#define DEF_CONSCRIPT_MIN_CULTURE_PERCENT GC.getGameDefines().getCONSCRIPT_MIN_CULTURE_PERCENT()
#define DEF_WE_LOVE_THE_KING_RAND GC.getGameDefines().getWE_LOVE_THE_KING_RAND()
#define DEF_ACO_ENABLED GC.getGameDefines().getACO_ENABLED()
#define DEF_CURSOR_SIZENW GC.getGameDefines().getCURSOR_SIZENW()
#define DEF_NEW_CITY_BUILDING_VALUE_MODIFIER GC.getGameDefines().getNEW_CITY_BUILDING_VALUE_MODIFIER()
#define DEF_NPC1_LEADER GC.getGameDefines().getNPC1_LEADER()
#define DEF_START_YEAR GC.getGameDefines().getSTART_YEAR()
#define DEF_USE_ON_UNIT_CREATED_CALLBACK GC.getGameDefines().getUSE_ON_UNIT_CREATED_CALLBACK()
#define DEF_BANDIT_SPAWN_MODIFIER GC.getGameDefines().getBANDIT_SPAWN_MODIFIER()
#define DEF_CURSOR_SPLITV GC.getGameDefines().getCURSOR_SPLITV()
#define DEF_NPC2_LEADER GC.getGameDefines().getNPC2_LEADER()
#define DEF_GOLDEN_AGE_UNITS_MULTIPLIER GC.getGameDefines().getGOLDEN_AGE_UNITS_MULTIPLIER()
#define DEF_NPC3_LEADER GC.getGameDefines().getNPC3_LEADER()
#define DEF_AI_HANDICAP GC.getGameDefines().getAI_HANDICAP()
#define DEF_NPC4_LEADER GC.getGameDefines().getNPC4_LEADER()
#define DEF_PAGE_IN_DIST_SYMBOLS GC.getGameDefines().getPAGE_IN_DIST_SYMBOLS()
#define DEF_CITY_DEFENSE_DAMAGE_HEAL_RATE GC.getGameDefines().getCITY_DEFENSE_DAMAGE_HEAL_RATE()
#define DEF_DEFAULT_FLEXIBLE_DIFFICULTY_TURN_INCREMENTS GC.getGameDefines().getDEFAULT_FLEXIBLE_DIFFICULTY_TURN_INCREMENTS()
#define DEF_NPC5_LEADER GC.getGameDefines().getNPC5_LEADER()
#define DEF_USE_CAN_TRAIN_CALLBACK GC.getGameDefines().getUSE_CAN_TRAIN_CALLBACK()
#define DEF_NPC6_LEADER GC.getGameDefines().getNPC6_LEADER()
#define DEF_NPC7_LEADER GC.getGameDefines().getNPC7_LEADER()
#define DEF_NUM_UNIT_PREREQ_OR_BONUSES GC.getGameDefines().getNUM_UNIT_PREREQ_OR_BONUSES()
#define DEF_BASE_RELIGION_ANARCHY_LENGTH GC.getGameDefines().getBASE_RELIGION_ANARCHY_LENGTH()
#define DEF_FOREIGN_TRADE_MODIFIER GC.getGameDefines().getFOREIGN_TRADE_MODIFIER()
#define DEF_NPC8_LEADER GC.getGameDefines().getNPC8_LEADER()
#define DEF_PAGE_IN_DIST_FEATURES GC.getGameDefines().getPAGE_IN_DIST_FEATURES()
#define DEF_SPY_DESTROY_COST_MULTIPLIER GC.getGameDefines().getSPY_DESTROY_COST_MULTIPLIER()
#define DEF_CAN_TRADE_GOLD GC.getGameDefines().getCAN_TRADE_GOLD()
#define DEF_WAR_PRIZES GC.getGameDefines().getWAR_PRIZES()
#define DEF_CAN_TRADE_CORPORATIONS GC.getGameDefines().getCAN_TRADE_CORPORATIONS()
#define DEF_GW_MOD_ENABLED GC.getGameDefines().getGW_MOD_ENABLED()
#define DEF_LIMITED_RELIGIONS_EXCEPTIONS GC.getGameDefines().getLIMITED_RELIGIONS_EXCEPTIONS()
#define DEF_UNIT_MULTISELECT_MAX GC.getGameDefines().getUNIT_MULTISELECT_MAX()
#define DEF_WARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT GC.getGameDefines().getWARLORD_EXTRA_EXPERIENCE_PER_UNIT_PERCENT()
#define DEF_CAPITAL_TRADE_MODIFIER GC.getGameDefines().getCAPITAL_TRADE_MODIFIER()
#define DEF_COMMERCE_PERCENT_CHANGE_INCREMENTS GC.getGameDefines().getCOMMERCE_PERCENT_CHANGE_INCREMENTS()
#define DEF_USE_CAN_DO_PLOT_CULTURE_CALLBACK GC.getGameDefines().getUSE_CAN_DO_PLOT_CULTURE_CALLBACK()
#define DEF_INCREASING_DIFFICULTY_TURN_CHECK_INCREMENTS GC.getGameDefines().getINCREASING_DIFFICULTY_TURN_CHECK_INCREMENTS()
#define DEF_CITY_SCREEN_FOG_ENABLED GC.getGameDefines().getCITY_SCREEN_FOG_ENABLED()
#define DEF_GREAT_GENERALS_THRESHOLD_INCREASE GC.getGameDefines().getGREAT_GENERALS_THRESHOLD_INCREASE()
#define DEF_NUM_BUILDING_AND_TECH_PREREQS GC.getGameDefines().getNUM_BUILDING_AND_TECH_PREREQS()
#define DEF_TRADE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT GC.getGameDefines().getTRADE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT()
#define DEF_BUG_UNIT_EXPERIENCE_MODIFIERS_HOVER GC.getGameDefines().getBUG_UNIT_EXPERIENCE_MODIFIERS_HOVER()
#define DEF_UNIT_UPGRADE_COST_PER_PRODUCTION GC.getGameDefines().getUNIT_UPGRADE_COST_PER_PRODUCTION()
#define DEF_ACO_SHOW_DEFENDER_HEALTH_BARS GC.getGameDefines().getACO_SHOW_DEFENDER_HEALTH_BARS()
#define DEF_BARREN_TERRAIN GC.getGameDefines().getBARREN_TERRAIN()
#define DEF_IDW_ENABLED GC.getGameDefines().getIDW_ENABLED()
#define DEF_TREAT_NEGATIVE_GOLD_AS_MAINTENANCE GC.getGameDefines().getTREAT_NEGATIVE_GOLD_AS_MAINTENANCE()
#define DEF_BUG_CITYBAR_HURRY_ANGER GC.getGameDefines().getBUG_CITYBAR_HURRY_ANGER()
#define DEF_CONSCRIPT_MIN_CITY_POPULATION GC.getGameDefines().getCONSCRIPT_MIN_CITY_POPULATION()
#define DEF_DEFY_RESOLUTION_ANGER_DIVISOR GC.getGameDefines().getDEFY_RESOLUTION_ANGER_DIVISOR()
#define DEF_CAN_TRADE_MAPS GC.getGameDefines().getCAN_TRADE_MAPS()
#define DEF_CORPORATION_RESOURCE_BASE_INFLUENCE GC.getGameDefines().getCORPORATION_RESOURCE_BASE_INFLUENCE()
#define DEF_ACO_FORCE_ORIGINAL_ODDS GC.getGameDefines().getACO_FORCE_ORIGINAL_ODDS()
#define DEF_USE_ON_UPDATE_CALLBACK GC.getGameDefines().getUSE_ON_UPDATE_CALLBACK()
#define DEF_VIEWPORT_FOCUS_BORDER GC.getGameDefines().getVIEWPORT_FOCUS_BORDER()
#define DEF_BUG_CITYBAR_SPECIALISTS GC.getGameDefines().getBUG_CITYBAR_SPECIALISTS()
#define DEF_EVENT_PROBABILITY_ROLL_SIDES GC.getGameDefines().getEVENT_PROBABILITY_ROLL_SIDES()
#define DEF_MAX_EVASION_PROBABILITY GC.getGameDefines().getMAX_EVASION_PROBABILITY()
#define DEF_MIN_REVOLUTION_TURNS GC.getGameDefines().getMIN_REVOLUTION_TURNS()
#define DEF_SCORE_HANDICAP_PERCENT_OFFSET GC.getGameDefines().getSCORE_HANDICAP_PERCENT_OFFSET()
#define DEF_UNIT_PRODUCTION_DECAY_PERCENT GC.getGameDefines().getUNIT_PRODUCTION_DECAY_PERCENT()
#define DEF_AMPHIB_ATTACK_MODIFIER GC.getGameDefines().getAMPHIB_ATTACK_MODIFIER()
#define DEF_ESPIONAGE_SPENDING_MULTIPLIER GC.getGameDefines().getESPIONAGE_SPENDING_MULTIPLIER()
#define DEF_GREATER_COMMERCE_SWITCH_POINT GC.getGameDefines().getGREATER_COMMERCE_SWITCH_POINT()
#define DEF_BATTLEFIELD_PROMOTIONS GC.getGameDefines().getBATTLEFIELD_PROMOTIONS()
#define DEF_C2C_ROUGH_BOMBARD_VALUE_MODIFIER GC.getGameDefines().getC2C_ROUGH_BOMBARD_VALUE_MODIFIER()
#define DEF_ADVANCED_START_CULTURE_COST GC.getGameDefines().getADVANCED_START_CULTURE_COST()
#define DEF_RELIGION_SPREAD_DISTANCE_DIVISOR GC.getGameDefines().getRELIGION_SPREAD_DISTANCE_DIVISOR()
#define DEF_ROUTE_FEATURE_GROWTH_MODIFIER GC.getGameDefines().getROUTE_FEATURE_GROWTH_MODIFIER()
#define DEF_WE_LOVE_THE_KING_POPULATION_MIN_POPULATION GC.getGameDefines().getWE_LOVE_THE_KING_POPULATION_MIN_POPULATION()
#define DEF_BBAI_ATTACK_CITY_STACK_RATIO GC.getGameDefines().getBBAI_ATTACK_CITY_STACK_RATIO()
#define DEF_BBAI_DEFENSIVE_PACT_BEHAVIOR GC.getGameDefines().getBBAI_DEFENSIVE_PACT_BEHAVIOR()
#define DEF_CONSCRIPT_ANGER_DIVISOR GC.getGameDefines().getCONSCRIPT_ANGER_DIVISOR()
#define DEF_BASE_SPY_DESTROY_COST GC.getGameDefines().getBASE_SPY_DESTROY_COST()
#define DEF_BUG_BUILDING_ADDITIONAL_FOOD_HOVER GC.getGameDefines().getBUG_BUILDING_ADDITIONAL_FOOD_HOVER()
#define DEF_BUG_CITYBAR_HIDE_INSTRUCTIONS GC.getGameDefines().getBUG_CITYBAR_HIDE_INSTRUCTIONS()
#define DEF_CURSOR_AIRBOMB GC.getGameDefines().getCURSOR_AIRBOMB()
#define DEF_INQUISITION_BUILDING_GOLD_DIVISOR GC.getGameDefines().getINQUISITION_BUILDING_GOLD_DIVISOR()
#define DEF_WW_ATTACKED_WITH_NUKE GC.getGameDefines().getWW_ATTACKED_WITH_NUKE()
#define DEF_ADVANCED_START_CITY_COST_INCREASE GC.getGameDefines().getADVANCED_START_CITY_COST_INCREASE()
#define DEF_BUILDING_PRODUCTION_DECAY_PERCENT GC.getGameDefines().getBUILDING_PRODUCTION_DECAY_PERCENT()
#define DEF_RIVAL_TEAM_STARTING_MODIFIER GC.getGameDefines().getRIVAL_TEAM_STARTING_MODIFIER()
#define DEF_BBAI_SKIP_BOMBARD_BASE_STACK_RATIO GC.getGameDefines().getBBAI_SKIP_BOMBARD_BASE_STACK_RATIO()
#define DEF_STANDARD_HANDICAP_QUICK GC.getGameDefines().getSTANDARD_HANDICAP_QUICK()
#define DEF_BUG_BUILDING_ADDITIONAL_GREAT_PEOPLE_HOVER GC.getGameDefines().getBUG_BUILDING_ADDITIONAL_GREAT_PEOPLE_HOVER()
#define DEF_CAN_TRADE_CONTACT GC.getGameDefines().getCAN_TRADE_CONTACT()
#define DEF_CITY_HEAL_RATE GC.getGameDefines().getCITY_HEAL_RATE()
#define DEF_ESPIONAGE_INTERCEPT_COUNTERESPIONAGE_MISSION GC.getGameDefines().getESPIONAGE_INTERCEPT_COUNTERESPIONAGE_MISSION()
#define DEF_USE_CANNOT_CONSTRUCT_CALLBACK GC.getGameDefines().getUSE_CANNOT_CONSTRUCT_CALLBACK()
#define DEF_ALWAYS_USE_MAX_COMPAT_SAVES GC.getGameDefines().getALWAYS_USE_MAX_COMPAT_SAVES()
#define DEF_BARBARIAN_LEADER GC.getGameDefines().getBARBARIAN_LEADER()
#define DEF_BUG_CITYBAR_BASE_VALUES GC.getGameDefines().getBUG_CITYBAR_BASE_VALUES()
#define DEF_USE_ON_UNIT_SELECTED_CALLBACK GC.getGameDefines().getUSE_ON_UNIT_SELECTED_CALLBACK()
#define DEF_LAKE_PLOT_RAND GC.getGameDefines().getLAKE_PLOT_RAND()
#define DEF_NUM_LAKE_NAMES GC.getGameDefines().getNUM_LAKE_NAMES()
#define DEF_ACO_SHOW_ATTACKER_HEALTH_BARS GC.getGameDefines().getACO_SHOW_ATTACKER_HEALTH_BARS()
#define DEF_ACO_SHOW_DEFENDER_INFO GC.getGameDefines().getACO_SHOW_DEFENDER_INFO()
#define DEF_BATTLE_EFFECT_LESS_PRODUCTION GC.getGameDefines().getBATTLE_EFFECT_LESS_PRODUCTION()
#define DEF_FREE_TRADE_CORPORATION_SPREAD_MOD GC.getGameDefines().getFREE_TRADE_CORPORATION_SPREAD_MOD()
#define DEF_NUKE_POPULATION_DEATH_RAND_1 GC.getGameDefines().getNUKE_POPULATION_DEATH_RAND_1()
#define DEF_NUKE_POPULATION_DEATH_RAND_2 GC.getGameDefines().getNUKE_POPULATION_DEATH_RAND_2()
#define DEF_NO_ESPIONAGE_CULTURE_LEVEL_MODIFIER GC.getGameDefines().getNO_ESPIONAGE_CULTURE_LEVEL_MODIFIER()
#define DEF_BUG_SPECIALIST_HOVER_ACTUAL_EFFECTS GC.getGameDefines().getBUG_SPECIALIST_HOVER_ACTUAL_EFFECTS()
#define DEF_CORPORATION_SPREAD_RAND GC.getGameDefines().getCORPORATION_SPREAD_RAND()
#define DEF_CURSOR_DEFAULT GC.getGameDefines().getCURSOR_DEFAULT()
#define DEF_BUG_CITYBAR_STARVATION_TURNS GC.getGameDefines().getBUG_CITYBAR_STARVATION_TURNS()
#define DEF_CAN_TRADE_OPEN_BORDERS GC.getGameDefines().getCAN_TRADE_OPEN_BORDERS()
#define DEF_MAX_EXPERIENCE_AFTER_UPGRADE GC.getGameDefines().getMAX_EXPERIENCE_AFTER_UPGRADE()
#define DEF_NUM_PEAK_NAMES GC.getGameDefines().getNUM_PEAK_NAMES()
#define DEF_TEST_GAMEFONTS GC.getGameDefines().getTEST_GAMEFONTS()
#define DEF_ACO_SHOW_UNHARMED_ODDS GC.getGameDefines().getACO_SHOW_UNHARMED_ODDS()
#define DEF_BUG_CITYBAR_FOOD_ASSIST GC.getGameDefines().getBUG_CITYBAR_FOOD_ASSIST()
#define DEF_CAN_TRADE_EMBARGO GC.getGameDefines().getCAN_TRADE_EMBARGO()
#define DEF_INITIAL_OUTSIDE_UNIT_GOLD_PERCENT GC.getGameDefines().getINITIAL_OUTSIDE_UNIT_GOLD_PERCENT()
#define DEF_SS_ASSASSINATE GC.getGameDefines().getSS_ASSASSINATE()
#define DEF_AIR_COMBAT_DAMAGE GC.getGameDefines().getAIR_COMBAT_DAMAGE()
#define DEF_DCM_RANGE_BOMBARD GC.getGameDefines().getDCM_RANGE_BOMBARD()
#define DEF_DCM_RB_CITY_INACCURACY GC.getGameDefines().getDCM_RB_CITY_INACCURACY()
#define DEF_BBAI_VICTORY_STRATEGY_CULTURE GC.getGameDefines().getBBAI_VICTORY_STRATEGY_CULTURE()
#define DEF_CAN_TRADE_CITIES GC.getGameDefines().getCAN_TRADE_CITIES()
#define DEF_CAN_TRADE_CIVICS GC.getGameDefines().getCAN_TRADE_CIVICS()
#define DEF_ENABLE_DYNAMIC_UNIT_ENTITIES GC.getGameDefines().getENABLE_DYNAMIC_UNIT_ENTITIES()
#define DEF_MAX_DISTANCE_CITY_MAINTENANCE GC.getGameDefines().getMAX_DISTANCE_CITY_MAINTENANCE()
#define DEF_CURSOR_AIRLIFT GC.getGameDefines().getCURSOR_AIRLIFT()
#define DEF_DCM_STACK_ATTACK GC.getGameDefines().getDCM_STACK_ATTACK()
#define DEF_FROZEN_TERRAIN GC.getGameDefines().getFROZEN_TERRAIN()
#define DEF_MIN_CITY_RANGE GC.getGameDefines().getMIN_CITY_RANGE()
#define DEF_TEMPERATE_FEATURE GC.getGameDefines().getTEMPERATE_FEATURE()
#define DEF_ROUTES_UPGRADE GC.getGameDefines().getROUTES_UPGRADE()
#define DEF_AI_SHOULDNT_MANAGE_PLOT_ASSIGNMENT GC.getGameDefines().getAI_SHOULDNT_MANAGE_PLOT_ASSIGNMENT()
#define DEF_FEATURE_GROWTH_MODIFIER GC.getGameDefines().getFEATURE_GROWTH_MODIFIER()
#define DEF_GREAT_PEOPLE_THRESHOLD GC.getGameDefines().getGREAT_PEOPLE_THRESHOLD()
#define DEF_INITIAL_CITY_POPULATION GC.getGameDefines().getINITIAL_CITY_POPULATION()
#define DEF_CIVILOPEDIA_SHOW_ACTIVE_CIVS_ONLY GC.getGameDefines().getCIVILOPEDIA_SHOW_ACTIVE_CIVS_ONLY()
#define DEF_ESPIONAGE_INTERCEPT_RECENT_MISSION GC.getGameDefines().getESPIONAGE_INTERCEPT_RECENT_MISSION()
#define DEF_SUPER_FORTS_DURATION_BEFORE_REVOLT GC.getGameDefines().getSUPER_FORTS_DURATION_BEFORE_REVOLT()
#define DEF_BUG_CITYBAR_BUILDING_ACTUAL_EFFECTS GC.getGameDefines().getBUG_CITYBAR_BUILDING_ACTUAL_EFFECTS()
#define DEF_ESPIONAGE_CITY_HOLY_CITY_MOD GC.getGameDefines().getESPIONAGE_CITY_HOLY_CITY_MOD()
#define DEF_VICTORY_SOUNDTRACK_AVAILABLE GC.getGameDefines().getVICTORY_SOUNDTRACK_AVAILABLE()
#define DEF_BARBARIAN_CIVILIZATION GC.getGameDefines().getBARBARIAN_CIVILIZATION()
#define DEF_BASE_UNIT_UPGRADE_COST GC.getGameDefines().getBASE_UNIT_UPGRADE_COST()
#define DEF_MAX_BUILDINGS_PER_CITY GC.getGameDefines().getMAX_BUILDINGS_PER_CITY()
#define DEF_BASE_SPY_SABOTAGE_COST GC.getGameDefines().getBASE_SPY_SABOTAGE_COST()
#define DEF_BBAI_SKIP_BOMBARD_BEST_ATTACK_ODDS GC.getGameDefines().getBBAI_SKIP_BOMBARD_BEST_ATTACK_ODDS()
#define DEF_BUG_PLOT_HOVER_PARTIAL_BUILDS GC.getGameDefines().getBUG_PLOT_HOVER_PARTIAL_BUILDS()
#define DEF_IDW_NO_NAVAL_INFLUENCE GC.getGameDefines().getIDW_NO_NAVAL_INFLUENCE()
#define DEF_INITIAL_BASE_FREE_UNITS GC.getGameDefines().getINITIAL_BASE_FREE_UNITS()
#define DEF_CURSOR_SIZEALL GC.getGameDefines().getCURSOR_SIZEALL()
#define DEF_GLOBAL_WARMING_TERRAIN GC.getGameDefines().getGLOBAL_WARMING_TERRAIN()
#define DEF_MAX_INTERCEPTION_PROBABILITY GC.getGameDefines().getMAX_INTERCEPTION_PROBABILITY()
#define DEF_STANDARD_HANDICAP GC.getGameDefines().getSTANDARD_HANDICAP()
#define DEF_ACO_SHOW_ATTACKER_INFO GC.getGameDefines().getACO_SHOW_ATTACKER_INFO()
#define DEF_BBAI_TURTLE_ENEMY_POWER_RATIO GC.getGameDefines().getBBAI_TURTLE_ENEMY_POWER_RATIO()
#define DEF_CONSCRIPT_POPULATION_PER_COST GC.getGameDefines().getCONSCRIPT_POPULATION_PER_COST()
#define DEF_GAMEFONT_TGA_RELIGIONS GC.getGameDefines().getGAMEFONT_TGA_RELIGIONS()
#define DEF_USE_CAN_DO_PRODUCTION_CALLBACK GC.getGameDefines().getUSE_CAN_DO_PRODUCTION_CALLBACK()
#define DEF_BUILDING_PRODUCTION_PERCENT GC.getGameDefines().getBUILDING_PRODUCTION_PERCENT()
#define DEF_EVENT_MESSAGE_TIME_LONG GC.getGameDefines().getEVENT_MESSAGE_TIME_LONG()
#define DEF_MIN_INTERCEPTION_DAMAGE GC.getGameDefines().getMIN_INTERCEPTION_DAMAGE()
#define DEF_RIVER_RAND_ON_MORE_RIVERS GC.getGameDefines().getRIVER_RAND_ON_MORE_RIVERS()
#define DEF_STANDARD_CALENDAR GC.getGameDefines().getSTANDARD_CALENDAR()
#define DEF_TEMPERATE_TERRAIN GC.getGameDefines().getTEMPERATE_TERRAIN()
#define DEF_USE_CAN_DO_GROWTH_CALLBACK GC.getGameDefines().getUSE_CAN_DO_GROWTH_CALLBACK()
#define DEF_ACO_SHOW_UNROUNDED_EXPERIENCE GC.getGameDefines().getACO_SHOW_UNROUNDED_EXPERIENCE()
#define DEF_CAPITAL_BUILDINGCLASS GC.getGameDefines().getCAPITAL_BUILDINGCLASS()
#define DEF_TECH_COST_FIRST_KNOWN_PREREQ_MODIFIER GC.getGameDefines().getTECH_COST_FIRST_KNOWN_PREREQ_MODIFIER()
#define DEF_UNIT_PRODUCTION_PERCENT GC.getGameDefines().getUNIT_PRODUCTION_PERCENT()
#define DEF_ADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES GC.getGameDefines().getADVANCED_START_ALLOW_UNITS_OUTSIDE_CITIES()
#define DEF_BUG_CITYBAR_HURRY_ASSIST_INCLUDE_CURRENT GC.getGameDefines().getBUG_CITYBAR_HURRY_ASSIST_INCLUDE_CURRENT()
#define DEF_CURSOR_GO_TO GC.getGameDefines().getCURSOR_GO_TO()
#define DEF_FORCED_WAR_WAR_WEARINESS_MODIFIER GC.getGameDefines().getFORCED_WAR_WAR_WEARINESS_MODIFIER()
#define DEF_MIN_POP_CONSIDER_INQUISITORS GC.getGameDefines().getMIN_POP_CONSIDER_INQUISITORS()
#define DEF_NPC1_CIVILIZATION GC.getGameDefines().getNPC1_CIVILIZATION()
#define DEF_NPC2_CIVILIZATION GC.getGameDefines().getNPC2_CIVILIZATION()
#define DEF_NPC3_CIVILIZATION GC.getGameDefines().getNPC3_CIVILIZATION()
#define DEF_NPC4_CIVILIZATION GC.getGameDefines().getNPC4_CIVILIZATION()
#define DEF_NPC5_CIVILIZATION GC.getGameDefines().getNPC5_CIVILIZATION()
#define DEF_NPC6_CIVILIZATION GC.getGameDefines().getNPC6_CIVILIZATION()
#define DEF_NPC7_CIVILIZATION GC.getGameDefines().getNPC7_CIVILIZATION()
#define DEF_NPC8_CIVILIZATION GC.getGameDefines().getNPC8_CIVILIZATION()
#define DEF_RECON_VISIBILITY_RANGE GC.getGameDefines().getRECON_VISIBILITY_RANGE()
#define DEF_CAN_TRADE_GOLD_PER_TURN GC.getGameDefines().getCAN_TRADE_GOLD_PER_TURN()
#define DEF_DYNAMIC_CIV_NAMES GC.getGameDefines().getDYNAMIC_CIV_NAMES()
#define DEF_LAKE_MAX_AREA_SIZE GC.getGameDefines().getLAKE_MAX_AREA_SIZE()
#define DEF_MIN_WATER_SIZE_FOR_OCEAN GC.getGameDefines().getMIN_WATER_SIZE_FOR_OCEAN()
#define DEF_NUKE_POPULATION_DEATH_BASE GC.getGameDefines().getNUKE_POPULATION_DEATH_BASE()
#define DEF_NUKE_UNIT_DAMAGE_RAND_1 GC.getGameDefines().getNUKE_UNIT_DAMAGE_RAND_1()
#define DEF_NUKE_UNIT_DAMAGE_RAND_2 GC.getGameDefines().getNUKE_UNIT_DAMAGE_RAND_2()
#define DEF_PEAK_EXTRA_DEFENSE GC.getGameDefines().getPEAK_EXTRA_DEFENSE()
#define DEF_OCCUPATION_CULTURE_PERCENT_THRESHOLD GC.getGameDefines().getOCCUPATION_CULTURE_PERCENT_THRESHOLD()
#define DEF_BUG_BUILDING_SAVED_MAINTENANCE_HOVER GC.getGameDefines().getBUG_BUILDING_SAVED_MAINTENANCE_HOVER()
#define DEF_BUG_PRODUCTION_DECAY_HOVER_BUILDING_THRESHOLD GC.getGameDefines().getBUG_PRODUCTION_DECAY_HOVER_BUILDING_THRESHOLD()
#define DEF_BUG_PRODUCTION_DECAY_HOVER_UNIT_THRESHOLD GC.getGameDefines().getBUG_PRODUCTION_DECAY_HOVER_UNIT_THRESHOLD()
#define DEF_BUG_SPED_UP_TECHS_HOVER GC.getGameDefines().getBUG_SPED_UP_TECHS_HOVER()
#define DEF_CIVIC_ANARCHY_QTY_DISCOUNT GC.getGameDefines().getCIVIC_ANARCHY_QTY_DISCOUNT()
#define DEF_SAD_MAX_MODIFIER GC.getGameDefines().getSAD_MAX_MODIFIER()
#define DEF_WW_DECAY_PEACE_PERCENT GC.getGameDefines().getWW_DECAY_PEACE_PERCENT()
#define DEF_CAN_TRADE_WORKERS GC.getGameDefines().getCAN_TRADE_WORKERS()
#define DEF_FIRST_EVENT_DELAY_TURNS GC.getGameDefines().getFIRST_EVENT_DELAY_TURNS()
#define DEF_MAX_CITY_DEFENSE_DAMAGE GC.getGameDefines().getMAX_CITY_DEFENSE_DAMAGE()
#define DEF_USE_CANNOT_HANDLE_ACTION_CALLBACK GC.getGameDefines().getUSE_CANNOT_HANDLE_ACTION_CALLBACK()
#define DEF_ACO_SWAP_VIEWS GC.getGameDefines().getACO_SWAP_VIEWS()
#define DEF_BONUS_OBSOLETE_VALUE_MODIFIER GC.getGameDefines().getBONUS_OBSOLETE_VALUE_MODIFIER()
#define DEF_BUG_CITYBAR_HAPPINESS GC.getGameDefines().getBUG_CITYBAR_HAPPINESS()
#define DEF_BUG_CITY_SCREEN_BASE_COMMERCE_HOVER GC.getGameDefines().getBUG_CITY_SCREEN_BASE_COMMERCE_HOVER()
#define DEF_CITY_GROWTH_MULTIPLIER GC.getGameDefines().getCITY_GROWTH_MULTIPLIER()
#define DEF_EXTRA_YIELD GC.getGameDefines().getEXTRA_YIELD()
#define DEF_LAND_UNITS_CAN_ATTACK_WATER_CITIES GC.getGameDefines().getLAND_UNITS_CAN_ATTACK_WATER_CITIES()
#define DEF_PLOTS_PER_RIVER_EDGE_DIVISOR GC.getGameDefines().getPLOTS_PER_RIVER_EDGE_DIVISOR()
#define DEF_ADVANCED_START_MAX_UNITS_PER_CITY GC.getGameDefines().getADVANCED_START_MAX_UNITS_PER_CITY()
#define DEF_RELIGION_PERCENT_ANGER GC.getGameDefines().getRELIGION_PERCENT_ANGER()
#define DEF_USE_AI_UPDATE_UNIT_CALLBACK GC.getGameDefines().getUSE_AI_UPDATE_UNIT_CALLBACK()
#define DEF_ESPIONAGE_DISTANCE_MULTIPLIER_MOD GC.getGameDefines().getESPIONAGE_DISTANCE_MULTIPLIER_MOD()
#define DEF_HIGH_TO_LOW_FIRST_TURN_CHECK GC.getGameDefines().getHIGH_TO_LOW_FIRST_TURN_CHECK()
#define DEF_ZOOM_CITY_FOR_PRODUCTION_POPUP GC.getGameDefines().getZOOM_CITY_FOR_PRODUCTION_POPUP()
#define DEF_ANIMAL_DAMAGE_PERCENT_AFTER_SUBDUE GC.getGameDefines().getANIMAL_DAMAGE_PERCENT_AFTER_SUBDUE()
#define DEF_MAX_INTERCEPTION_DAMAGE GC.getGameDefines().getMAX_INTERCEPTION_DAMAGE()
#define DEF_OVERSEAS_TRADE_MODIFIER GC.getGameDefines().getOVERSEAS_TRADE_MODIFIER()
#define DEF_PAGE_IN_DIST_ROUTE GC.getGameDefines().getPAGE_IN_DIST_ROUTE()
#define DEF_USE_GET_BUILDING_COST_MOD_CALLBACK GC.getGameDefines().getUSE_GET_BUILDING_COST_MOD_CALLBACK()
#define DEF_BARBARIAN_MAX_XP_VALUE GC.getGameDefines().getBARBARIAN_MAX_XP_VALUE()
#define DEF_BBAI_AIR_COMBAT GC.getGameDefines().getBBAI_AIR_COMBAT()
#define DEF_BBAI_BOMBARD_ATTACK_CITY_MAX_STACK_FRACTION GC.getGameDefines().getBBAI_BOMBARD_ATTACK_CITY_MAX_STACK_FRACTION()
#define DEF_BBAI_BOMBARD_ATTACK_STACK_FRACTION GC.getGameDefines().getBBAI_BOMBARD_ATTACK_STACK_FRACTION()
#define DEF_CAN_TRADE_PEACE GC.getGameDefines().getCAN_TRADE_PEACE()
#define DEF_USE_IS_VICTORY_CALLBACK GC.getGameDefines().getUSE_IS_VICTORY_CALLBACK()
#define DEF_USE_UNIT_CANNOT_MOVE_INTO_CALLBACK GC.getGameDefines().getUSE_UNIT_CANNOT_MOVE_INTO_CALLBACK()
#define DEF_BASE_SPY_STEAL_PLANS_COST GC.getGameDefines().getBASE_SPY_STEAL_PLANS_COST()
#define DEF_MAXED_BUILDING_GOLD_PERCENT GC.getGameDefines().getMAXED_BUILDING_GOLD_PERCENT()
#define DEF_MULTIPLAYER_WAR_WEARINESS_MODIFIER GC.getGameDefines().getMULTIPLAYER_WAR_WEARINESS_MODIFIER()
#define DEF_TURN_LOG_MAX_HEIGHT GC.getGameDefines().getTURN_LOG_MAX_HEIGHT()
#define DEF_WATER_POTENTIAL_CITY_WORK_FOR_AREA GC.getGameDefines().getWATER_POTENTIAL_CITY_WORK_FOR_AREA()
#define DEF_ESPIONAGE_CITY_RELIGION_STATE_MOD GC.getGameDefines().getESPIONAGE_CITY_RELIGION_STATE_MOD()
#define DEF_ESTABLISH_MODIFIER_PER_TURN GC.getGameDefines().getESTABLISH_MODIFIER_PER_TURN()
#define DEF_HURRY_INFLATION_DECAY_RATE GC.getGameDefines().getHURRY_INFLATION_DECAY_RATE()
#define DEF_MAXED_UNIT_GOLD_PERCENT GC.getGameDefines().getMAXED_UNIT_GOLD_PERCENT()
#define DEF_RUINS_IMPROVEMENT GC.getGameDefines().getRUINS_IMPROVEMENT()
#define DEF_SCORE_HANDICAP_PERCENT_PER GC.getGameDefines().getSCORE_HANDICAP_PERCENT_PER()
#define DEF_USE_CANNOT_SPREAD_RELIGION_CALLBACK GC.getGameDefines().getUSE_CANNOT_SPREAD_RELIGION_CALLBACK()
#define DEF_ADVANCED_START_CITY_PLACEMENT_MAX_RANGE GC.getGameDefines().getADVANCED_START_CITY_PLACEMENT_MAX_RANGE()
#define DEF_RIVER_SOURCE_MIN_RIVER_RANGE GC.getGameDefines().getRIVER_SOURCE_MIN_RIVER_RANGE()
#define DEF_TECH_DIFFUSION_KNOWN_TEAM_MODIFIER GC.getGameDefines().getTECH_DIFFUSION_KNOWN_TEAM_MODIFIER()
#define DEF_ADVANCED_START_VISIBILITY_COST_INCREASE GC.getGameDefines().getADVANCED_START_VISIBILITY_COST_INCREASE()
#define DEF_CAPTURE_GOLD_MAX_TURNS GC.getGameDefines().getCAPTURE_GOLD_MAX_TURNS()
#define DEF_COMMERCE_ATTACKS_FADE_RATE GC.getGameDefines().getCOMMERCE_ATTACKS_FADE_RATE()
#define DEF_GOlDEN_AGE_PERCENT_LESS_FOOD_FOR_GROWTH GC.getGameDefines().getGOlDEN_AGE_PERCENT_LESS_FOOD_FOR_GROWTH()
#define DEF_BASE_REVOLT_OCCUPATION_TURNS GC.getGameDefines().getBASE_REVOLT_OCCUPATION_TURNS()
#define DEF_BUG_IGNORE_HARMLESS_BARBARIANS GC.getGameDefines().getBUG_IGNORE_HARMLESS_BARBARIANS()
#define DEF_CURSOR_EDIT GC.getGameDefines().getCURSOR_EDIT()
#define DEF_DRY_TERRAIN GC.getGameDefines().getDRY_TERRAIN()
#define DEF_OWN_TEAM_STARTING_MODIFIER GC.getGameDefines().getOWN_TEAM_STARTING_MODIFIER()
#define DEF_CAN_TRADE_DEFENSIVE_PACT GC.getGameDefines().getCAN_TRADE_DEFENSIVE_PACT()
#define DEF_ESPIONAGE_CITY_POP_EACH_MOD GC.getGameDefines().getESPIONAGE_CITY_POP_EACH_MOD()
#define DEF_IDW_NO_BARBARIAN_INFLUENCE GC.getGameDefines().getIDW_NO_BARBARIAN_INFLUENCE()
#define DEF_NUM_JUNGLE_NAMES GC.getGameDefines().getNUM_JUNGLE_NAMES()
#define DEF_PASSIVE_ANIMAL_LEADER GC.getGameDefines().getPASSIVE_ANIMAL_LEADER()
#define DEF_ADVANCED_START_POPULATION_COST_INCREASE GC.getGameDefines().getADVANCED_START_POPULATION_COST_INCREASE()
#define DEF_BUG_BUILDING_ADDITIONAL_PRODUCTION_HOVER GC.getGameDefines().getBUG_BUILDING_ADDITIONAL_PRODUCTION_HOVER()
#define DEF_OUR_POPULATION_TRADE_MODIFIER GC.getGameDefines().getOUR_POPULATION_TRADE_MODIFIER()
#define DEF_COMBAT_DIE_SIDES GC.getGameDefines().getCOMBAT_DIE_SIDES()
#define DEF_FREE_TRADE_AGREEMENT_ESPIONAGE_MISSION_COST_MODIFIER GC.getGameDefines().getFREE_TRADE_AGREEMENT_ESPIONAGE_MISSION_COST_MODIFIER()
#define DEF_INITIAL_STATE_RELIGION_HAPPINESS GC.getGameDefines().getINITIAL_STATE_RELIGION_HAPPINESS()
#define DEF_MAX_HIT_POINTS GC.getGameDefines().getMAX_HIT_POINTS()
#define DEF_MAX_NATIONAL_WONDERS_PER_CITY GC.getGameDefines().getMAX_NATIONAL_WONDERS_PER_CITY()
#define DEF_PEAK_SEE_THROUGH_CHANGE GC.getGameDefines().getPEAK_SEE_THROUGH_CHANGE()
#define DEF_TURN_LOG_MIN_HEIGHT GC.getGameDefines().getTURN_LOG_MIN_HEIGHT()
#define DEF_BASE_REVOLT_FREE_UNITS GC.getGameDefines().getBASE_REVOLT_FREE_UNITS()
#define DEF_SIZE_MATTERS_MOST_MULTIPLIER GC.getGameDefines().getSIZE_MATTERS_MOST_MULTIPLIER()
#define DEF_USE_CAN_MAINTAIN_PROCESS_CALLBACK GC.getGameDefines().getUSE_CAN_MAINTAIN_PROCESS_CALLBACK()
#define DEF_WASTAGE_START_CONSUMPTION_PERCENT GC.getGameDefines().getWASTAGE_START_CONSUMPTION_PERCENT()
#define DEF_BUG_ASK_DECLARE_WAR_UNITS GC.getGameDefines().getBUG_ASK_DECLARE_WAR_UNITS()
#define DEF_BUG_PLOT_HOVER_LAT_LONG GC.getGameDefines().getBUG_PLOT_HOVER_LAT_LONG()
#define DEF_GOLDEN_AGE_LENGTH GC.getGameDefines().getGOLDEN_AGE_LENGTH()
#define DEF_MAXED_PROJECT_GOLD_PERCENT GC.getGameDefines().getMAXED_PROJECT_GOLD_PERCENT()
#define DEF_MAX_ANARCHY_TURNS GC.getGameDefines().getMAX_ANARCHY_TURNS()
#define DEF_MAX_PLOT_LIST_ROWS GC.getGameDefines().getMAX_PLOT_LIST_ROWS()
#define DEF_MIN_VERSION GC.getGameDefines().getMIN_VERSION()
#define DEF_NUM_DESERT_NAMES GC.getGameDefines().getNUM_DESERT_NAMES()
#define DEF_SS_BRIBE GC.getGameDefines().getSS_BRIBE()
#define DEF_BARBARIAN_SPAWN_MODIFIER GC.getGameDefines().getBARBARIAN_SPAWN_MODIFIER()
#define DEF_CAN_TRADE_WAR GC.getGameDefines().getCAN_TRADE_WAR()
#define DEF_CITY_AIR_UNIT_CAPACITY GC.getGameDefines().getCITY_AIR_UNIT_CAPACITY()
#define DEF_NEUTRAL_HEAL_RATE GC.getGameDefines().getNEUTRAL_HEAL_RATE()
#define DEF_SCORE_POPULATION_FACTOR GC.getGameDefines().getSCORE_POPULATION_FACTOR()
#define DEF_USE_MODDERS_PLAYEROPTION_1 GC.getGameDefines().getUSE_MODDERS_PLAYEROPTION_1()
#define DEF_USE_MODDERS_PLAYEROPTION_2 GC.getGameDefines().getUSE_MODDERS_PLAYEROPTION_2()
#define DEF_USE_MODDERS_PLAYEROPTION_3 GC.getGameDefines().getUSE_MODDERS_PLAYEROPTION_3()
#define DEF_BBAI_HUMAN_VASSAL_WAR_BUILD GC.getGameDefines().getBBAI_HUMAN_VASSAL_WAR_BUILD()
#define DEF_CURSOR_LINK GC.getGameDefines().getCURSOR_LINK()
#define DEF_CURSOR_PING GC.getGameDefines().getCURSOR_PING()
#define DEF_ESPIONAGE_SPY_INTERCEPT_MOD GC.getGameDefines().getESPIONAGE_SPY_INTERCEPT_MOD()
#define DEF_LANDMARK_ANGER_DIVISOR GC.getGameDefines().getLANDMARK_ANGER_DIVISOR()
#define DEF_MAX_TRADE_ROUTES GC.getGameDefines().getMAX_TRADE_ROUTES()
#define DEF_MAX_WITHDRAWAL_PROBABILITY GC.getGameDefines().getMAX_WITHDRAWAL_PROBABILITY()
#define DEF_NUM_FOREST_NAMES GC.getGameDefines().getNUM_FOREST_NAMES()
#define DEF_TAXATION_ANGER_ROUND_DOWN GC.getGameDefines().getTAXATION_ANGER_ROUND_DOWN()
#define DEF_BBAI_UNIT_CAPTURE GC.getGameDefines().getBBAI_UNIT_CAPTURE()
#define DEF_BUG_TECH_TRADE_DENIAL_HOVER GC.getGameDefines().getBUG_TECH_TRADE_DENIAL_HOVER()
#define DEF_COMBAT_EXPERIENCE_IN_BORDERS_PERCENT GC.getGameDefines().getCOMBAT_EXPERIENCE_IN_BORDERS_PERCENT()
#define DEF_CULTURE_PERCENT_ANGER GC.getGameDefines().getCULTURE_PERCENT_ANGER()
#define DEF_DCM_AIR_BOMBING GC.getGameDefines().getDCM_AIR_BOMBING()
#define DEF_USE_CAN_RAZE_CITY_CALLBACK GC.getGameDefines().getUSE_CAN_RAZE_CITY_CALLBACK()
#define DEF_AT_WAR_CULTURE_ANGER_MODIFIER GC.getGameDefines().getAT_WAR_CULTURE_ANGER_MODIFIER()
#define DEF_BASE_WAR_WEARINESS_MULTIPLIER GC.getGameDefines().getBASE_WAR_WEARINESS_MULTIPLIER()
#define DEF_BATTLE_EFFECT_LESS_FOOD GC.getGameDefines().getBATTLE_EFFECT_LESS_FOOD()
#define DEF_BUILDING_PRODUCTION_DECAY_TIME GC.getGameDefines().getBUILDING_PRODUCTION_DECAY_TIME()
#define DEF_INITIAL_TRADE_ROUTES GC.getGameDefines().getINITIAL_TRADE_ROUTES()
#define DEF_MAX_PLOT_LIST_SIZE GC.getGameDefines().getMAX_PLOT_LIST_SIZE()
#define DEF_RENDER_GLOBEVIEW_CLOUDS GC.getGameDefines().getRENDER_GLOBEVIEW_CLOUDS()
#define DEF_AI_WORKER_MAX_DISTANCE_FROM_CITY_OUT_BORDERS GC.getGameDefines().getAI_WORKER_MAX_DISTANCE_FROM_CITY_OUT_BORDERS()
#define DEF_UNIT_PRODUCTION_DECAY_TIME GC.getGameDefines().getUNIT_PRODUCTION_DECAY_TIME()
#define DEF_BUG_CITYBAR_TRADE_DETAIL GC.getGameDefines().getBUG_CITYBAR_TRADE_DETAIL()
#define DEF_CURSOR_GRIP GC.getGameDefines().getCURSOR_GRIP()
#define DEF_CURSOR_REBASE GC.getGameDefines().getCURSOR_REBASE()
#define DEF_DEFAULT_ANIM_PAGE_MAX GC.getGameDefines().getDEFAULT_ANIM_PAGE_MAX()
#define DEF_DIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT GC.getGameDefines().getDIFFERENT_TEAM_FEATURE_PRODUCTION_PERCENT()
#define DEF_MARSH_TERRAIN GC.getGameDefines().getMARSH_TERRAIN()
#define DEF_MOVE_DENOMINATOR GC.getGameDefines().getMOVE_DENOMINATOR()
#define DEF_WATER_IMPROVEMENT GC.getGameDefines().getWATER_IMPROVEMENT()
#define DEF_ACO_SHOW_AVERAGE_HEALTH GC.getGameDefines().getACO_SHOW_AVERAGE_HEALTH()
#define DEF_BUG_BUILDING_HOVER_ACTUAL_EFFECTS GC.getGameDefines().getBUG_BUILDING_HOVER_ACTUAL_EFFECTS()
#define DEF_CORPORATION_SPREAD_DISTANCE_DIVISOR GC.getGameDefines().getCORPORATION_SPREAD_DISTANCE_DIVISOR()
#define DEF_CURSOR_NUKE GC.getGameDefines().getCURSOR_NUKE()
#define DEF_FREE_CITY_CULTURE GC.getGameDefines().getFREE_CITY_CULTURE()
#define DEF_GLOBAL_WARMING_POWER_WEIGHT GC.getGameDefines().getGLOBAL_WARMING_POWER_WEIGHT()
#define DEF_MAX_DESIRED_MEMORY_USED GC.getGameDefines().getMAX_DESIRED_MEMORY_USED()
#define DEF_PLAYER_ALWAYS_RAZES_CITIES GC.getGameDefines().getPLAYER_ALWAYS_RAZES_CITIES()
#define DEF_SEAWATER_SEE_THROUGH_CHANGE GC.getGameDefines().getSEAWATER_SEE_THROUGH_CHANGE()
#define DEF_SS_ENABLED GC.getGameDefines().getSS_ENABLED()
#define DEF_STANDARD_SEALEVEL GC.getGameDefines().getSTANDARD_SEALEVEL()
#define DEF_TURN_LOG_MAX_WIDTH GC.getGameDefines().getTURN_LOG_MAX_WIDTH()
#define DEF_WAR_SUCCESS_NUKE GC.getGameDefines().getWAR_SUCCESS_NUKE()
#define DEF_ACO_SHOW_SURVIVAL_ODDS GC.getGameDefines().getACO_SHOW_SURVIVAL_ODDS()
#define DEF_BUG_LEADERHEAD_HOVER_WORST_ENEMY GC.getGameDefines().getBUG_LEADERHEAD_HOVER_WORST_ENEMY()
#define DEF_CAPTURE_GOLD_PER_POPULATION GC.getGameDefines().getCAPTURE_GOLD_PER_POPULATION()
#define DEF_EMBASSY_ESPIONAGE_MISSION_COST_MODIFIER GC.getGameDefines().getEMBASSY_ESPIONAGE_MISSION_COST_MODIFIER()
#define DEF_RAND_CORPORATION_BEST_SPREAD GC.getGameDefines().getRAND_CORPORATION_BEST_SPREAD()
#define DEF_BUG_BUILDING_ADDITIONAL_HAPPINESS_HOVER GC.getGameDefines().getBUG_BUILDING_ADDITIONAL_HAPPINESS_HOVER()
#define DEF_COLLATERAL_COMBAT_DAMAGE GC.getGameDefines().getCOLLATERAL_COMBAT_DAMAGE()
#define DEF_SAFE_GOLD_PERCENT GC.getGameDefines().getSAFE_GOLD_PERCENT()
#define DEF_SCORE_TECH_FACTOR GC.getGameDefines().getSCORE_TECH_FACTOR()
#define DEF_USE_CAN_CREATE_PROJECT_CALLBACK GC.getGameDefines().getUSE_CAN_CREATE_PROJECT_CALLBACK()
#define DEF_GLOBAL_WARMING_NUKE_WEIGHT GC.getGameDefines().getGLOBAL_WARMING_NUKE_WEIGHT()
#define DEF_IDW_EMERGENCY_DRAFT_MIN_POPULATION GC.getGameDefines().getIDW_EMERGENCY_DRAFT_MIN_POPULATION()
#define DEF_INTERCEPTION_MAX_ROUNDS GC.getGameDefines().getINTERCEPTION_MAX_ROUNDS()
#define DEF_BBAI_SKIP_BOMBARD_MIN_STACK_RATIO GC.getGameDefines().getBBAI_SKIP_BOMBARD_MIN_STACK_RATIO()
#define DEF_CURSOR_MOVE GC.getGameDefines().getCURSOR_MOVE()
#define DEF_ENABLE_VIEWPORTS GC.getGameDefines().getENABLE_VIEWPORTS()
#define DEF_ESPIONAGE_INTERCEPT_SPENDING_MAX GC.getGameDefines().getESPIONAGE_INTERCEPT_SPENDING_MAX()
#define DEF_USE_AI_BESTTECH_CALLBACK GC.getGameDefines().getUSE_AI_BESTTECH_CALLBACK()
#define DEF_WEEKS_PER_MONTHS GC.getGameDefines().getWEEKS_PER_MONTHS()
#define DEF_CAN_TRADE_LIMITED_BORDERS GC.getGameDefines().getCAN_TRADE_LIMITED_BORDERS()
#define DEF_MAX_AIRLIFT_RANGE GC.getGameDefines().getMAX_AIRLIFT_RANGE()
#define DEF_MAX_NATIONAL_WONDERS_PER_CITY_FOR_OCC GC.getGameDefines().getMAX_NATIONAL_WONDERS_PER_CITY_FOR_OCC()
#define DEF_NUM_ROUTE_PREREQ_OR_BONUSES GC.getGameDefines().getNUM_ROUTE_PREREQ_OR_BONUSES()
#define DEF_SCORE_LAND_FACTOR GC.getGameDefines().getSCORE_LAND_FACTOR()
#define DEF_USE_CAN_DECLARE_WAR_CALLBACK GC.getGameDefines().getUSE_CAN_DECLARE_WAR_CALLBACK()
#define DEF_USE_CAN_DO_GOLD_CALLBACK GC.getGameDefines().getUSE_CAN_DO_GOLD_CALLBACK()
#define DEF_BUG_LEADERHEAD_HOVER_DEFENSIVE_PACTS GC.getGameDefines().getBUG_LEADERHEAD_HOVER_DEFENSIVE_PACTS()
#define DEF_MAX_NUM_LANGUAGES GC.getGameDefines().getMAX_NUM_LANGUAGES()
#define DEF_STANDARD_CLIMATE GC.getGameDefines().getSTANDARD_CLIMATE()
#define DEF_USE_CAN_DO_CULTURE_CALLBACK GC.getGameDefines().getUSE_CAN_DO_CULTURE_CALLBACK()
#define DEF_BBAI_VICTORY_STRATEGY_SPACE GC.getGameDefines().getBBAI_VICTORY_STRATEGY_SPACE()
#define DEF_TRADE_PROFIT_PERCENT GC.getGameDefines().getTRADE_PROFIT_PERCENT()
#define DEF_BUG_PRODUCTION_DECAY_HOVER GC.getGameDefines().getBUG_PRODUCTION_DECAY_HOVER()
#define DEF_INITIAL_CITY_ROUTE_TYPE GC.getGameDefines().getINITIAL_CITY_ROUTE_TYPE()
#define DEF_WAR_SUCCESS_ATTACKING GC.getGameDefines().getWAR_SUCCESS_ATTACKING()
#define DEF_WAR_SUCCESS_DEFENDING GC.getGameDefines().getWAR_SUCCESS_DEFENDING()
#define DEF_WW_CAPTURED_CITY GC.getGameDefines().getWW_CAPTURED_CITY()
#define DEF_BASE_GOLDEN_AGE_UNITS GC.getGameDefines().getBASE_GOLDEN_AGE_UNITS()
#define DEF_CHOOSE_RELIGION GC.getGameDefines().getCHOOSE_RELIGION()
#define DEF_NUM_CORPORATION_PREREQ_BONUSES GC.getGameDefines().getNUM_CORPORATION_PREREQ_BONUSES()
#define DEF_SIZE_MATTERS_MOST_VOLUMETRIC_MULTIPLIER GC.getGameDefines().getSIZE_MATTERS_MOST_VOLUMETRIC_MULTIPLIER()
#define DEF_USE_CAN_DO_GREATPEOPLE_CALLBACK GC.getGameDefines().getUSE_CAN_DO_GREATPEOPLE_CALLBACK()
#define DEF_USE_EXTRA_PLAYER_COSTS_CALLBACK GC.getGameDefines().getUSE_EXTRA_PLAYER_COSTS_CALLBACK()
#define DEF_VASSAL_REVOLT_MASTER_LOSSES_FACTOR GC.getGameDefines().getVASSAL_REVOLT_MASTER_LOSSES_FACTOR()
#define DEF_ADVANCED_START_CULTURE_COST_INCREASE GC.getGameDefines().getADVANCED_START_CULTURE_COST_INCREASE()
#define DEF_USE_GET_UNIT_COST_MOD_CALLBACK GC.getGameDefines().getUSE_GET_UNIT_COST_MOD_CALLBACK()
#define DEF_BUG_BUILDING_ADDITIONAL_COMMERCE_HOVER GC.getGameDefines().getBUG_BUILDING_ADDITIONAL_COMMERCE_HOVER()
#define DEF_CITY_MAX_NUM_BUILDINGS GC.getGameDefines().getCITY_MAX_NUM_BUILDINGS()
#define DEF_UNIT_PRODUCTION_PERCENT_SM GC.getGameDefines().getUNIT_PRODUCTION_PERCENT_SM()
#define DEF_USE_UPGRADE_UNIT_PRICE_CALLBACK GC.getGameDefines().getUSE_UPGRADE_UNIT_PRICE_CALLBACK()
#define DEF_VASSAL_HAPPINESS GC.getGameDefines().getVASSAL_HAPPINESS()
#define DEF_BUG_PRECHOP_IMPROVEMENTS GC.getGameDefines().getBUG_PRECHOP_IMPROVEMENTS()
#define DEF_CURSOR_AIRSTRIKE GC.getGameDefines().getCURSOR_AIRSTRIKE()
#define DEF_GOLDEN_AGE_GREAT_PEOPLE_MODIFIER GC.getGameDefines().getGOLDEN_AGE_GREAT_PEOPLE_MODIFIER()
#define DEF_IGNORE_PLOT_GROUP_FOR_TRADE_ROUTES GC.getGameDefines().getIGNORE_PLOT_GROUP_FOR_TRADE_ROUTES()
#define DEF_MIN_CITY_ATTACK_MODIFIER_FOR_SIEGE_TOWER GC.getGameDefines().getMIN_CITY_ATTACK_MODIFIER_FOR_SIEGE_TOWER()
#define DEF_BUG_BUILDING_ADDITIONAL_DEFENSE_HOVER GC.getGameDefines().getBUG_BUILDING_ADDITIONAL_DEFENSE_HOVER()
#define DEF_CITY_SCREEN_CLICK_WILL_EXIT GC.getGameDefines().getCITY_SCREEN_CLICK_WILL_EXIT()
#define DEF_OC_RESPAWN_HOLY_CITIES GC.getGameDefines().getOC_RESPAWN_HOLY_CITIES()
#define DEF_OWNERSHIP_SCORE_DURATION_THRESHOLD GC.getGameDefines().getOWNERSHIP_SCORE_DURATION_THRESHOLD()
#define DEF_REVOLT_TOTAL_CULTURE_MODIFIER GC.getGameDefines().getREVOLT_TOTAL_CULTURE_MODIFIER()
#define DEF_ACO_MERGE_SHORT_BARS GC.getGameDefines().getACO_MERGE_SHORT_BARS()
#define DEF_INITIAL_FREE_OUTSIDE_UNITS GC.getGameDefines().getINITIAL_FREE_OUTSIDE_UNITS()
#define DEF_NUM_BAY_NAMES GC.getGameDefines().getNUM_BAY_NAMES()
#define DEF_PEAK_SEE_FROM_CHANGE GC.getGameDefines().getPEAK_SEE_FROM_CHANGE()
#define DEF_SPY_DESTROY_COST_MULTIPLIER_LIMITED GC.getGameDefines().getSPY_DESTROY_COST_MULTIPLIER_LIMITED()
#define DEF_WW_DECAY_RATE GC.getGameDefines().getWW_DECAY_RATE()
#define DEF_WW_HIT_BY_NUKE GC.getGameDefines().getWW_HIT_BY_NUKE()
#define DEF_DIPLO_VOTE_SECRETARY_GENERAL_INTERVAL GC.getGameDefines().getDIPLO_VOTE_SECRETARY_GENERAL_INTERVAL()
#define DEF_HILLS_EXTRA_MOVEMENT GC.getGameDefines().getHILLS_EXTRA_MOVEMENT()
#define DEF_KILLERRABBIT_SPAWN_MODIFIER GC.getGameDefines().getKILLERRABBIT_SPAWN_MODIFIER()
#define DEF_RAZING_CULTURAL_PERCENT_THRESHOLD GC.getGameDefines().getRAZING_CULTURAL_PERCENT_THRESHOLD()
#define DEF_WW_CAPTURED_UNIT GC.getGameDefines().getWW_CAPTURED_UNIT()
#define DEF_ACO_SHOW_DEFENSE_MODIFIERS GC.getGameDefines().getACO_SHOW_DEFENSE_MODIFIERS()
#define DEF_BASE_CITY_GROWTH_THRESHOLD GC.getGameDefines().getBASE_CITY_GROWTH_THRESHOLD()
#define DEF_CURSOR_BUSY GC.getGameDefines().getCURSOR_BUSY()
#define DEF_ESPIONAGE_INTERCEPT_COUNTERSPY GC.getGameDefines().getESPIONAGE_INTERCEPT_COUNTERSPY()
#define DEF_ESPIONAGE_SPY_MISSION_ESCAPE_MOD GC.getGameDefines().getESPIONAGE_SPY_MISSION_ESCAPE_MOD()
#define DEF_GLOBAL_WARMING_BONUS_WEIGHT GC.getGameDefines().getGLOBAL_WARMING_BONUS_WEIGHT()
#define DEF_GLOBAL_WARMING_UNHEALTH_WEIGHT GC.getGameDefines().getGLOBAL_WARMING_UNHEALTH_WEIGHT()
#define DEF_INFILTRATE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT GC.getGameDefines().getINFILTRATE_MISSION_END_TOTAL_PERCENT_ADJUSTMENT()
#define DEF_INITIAL_AI_CITY_PRODUCTION GC.getGameDefines().getINITIAL_AI_CITY_PRODUCTION()
#define DEF_USE_AI_DO_DIPLO_CALLBACK GC.getGameDefines().getUSE_AI_DO_DIPLO_CALLBACK()
#define DEF_USE_CAN_RESEARCH_CALLBACK GC.getGameDefines().getUSE_CAN_RESEARCH_CALLBACK()
#define DEF_BUG_CITYBAR_AIRPORT_ICONS GC.getGameDefines().getBUG_CITYBAR_AIRPORT_ICONS()
#define DEF_ENEMY_HEAL_RATE GC.getGameDefines().getENEMY_HEAL_RATE()
#define DEF_FREE_CITY_ADJACENT_CULTURE GC.getGameDefines().getFREE_CITY_ADJACENT_CULTURE()
#define DEF_GREAT_PEOPLE_THRESHOLD_INCREASE_TEAM GC.getGameDefines().getGREAT_PEOPLE_THRESHOLD_INCREASE_TEAM()
#define DEF_IDW_INFLUENCE_RADIUS GC.getGameDefines().getIDW_INFLUENCE_RADIUS()
#define DEF_PERCENT_ANGER_DIVISOR GC.getGameDefines().getPERCENT_ANGER_DIVISOR()
#define DEF_RENDER_AREABORDER_UNDER_FEATURES GC.getGameDefines().getRENDER_AREABORDER_UNDER_FEATURES()
#define DEF_TECH_COST_TOTAL_KNOWN_TEAM_MODIFIER GC.getGameDefines().getTECH_COST_TOTAL_KNOWN_TEAM_MODIFIER()
#define DEF_WAR_SUCCESS_CITY_CAPTURING GC.getGameDefines().getWAR_SUCCESS_CITY_CAPTURING()
#define DEF_BUG_CITYBAR_CULTURE_TURNS GC.getGameDefines().getBUG_CITYBAR_CULTURE_TURNS()
#define DEF_MINIMUM_MOUNTAIN_RANGE_SIZE GC.getGameDefines().getMINIMUM_MOUNTAIN_RANGE_SIZE()
#define DEF_OCCUPATION_TURNS_POPULATION_PERCENT GC.getGameDefines().getOCCUPATION_TURNS_POPULATION_PERCENT()
#define DEF_PAGE_IN_DIST_CITY GC.getGameDefines().getPAGE_IN_DIST_CITY()
#define DEF_TEAM_VOTE_MIN_CANDIDATES GC.getGameDefines().getTEAM_VOTE_MIN_CANDIDATES()
#define DEF_USE_AI_CHOOSE_PRODUCTION_CALLBACK GC.getGameDefines().getUSE_AI_CHOOSE_PRODUCTION_CALLBACK()
#define DEF_MIN_TIMER_UNIT_DOUBLE_MOVES GC.getGameDefines().getMIN_TIMER_UNIT_DOUBLE_MOVES()
#define DEF_PROJECT_PRODUCTION_PERCENT GC.getGameDefines().getPROJECT_PRODUCTION_PERCENT()
#define DEF_BUG_CONSCRIPT_LIMIT_HOVER GC.getGameDefines().getBUG_CONSCRIPT_LIMIT_HOVER()
#define DEF_GLOBAL_WARMING_FOREST GC.getGameDefines().getGLOBAL_WARMING_FOREST()
#define DEF_MAX_FORTIFY_TURNS GC.getGameDefines().getMAX_FORTIFY_TURNS()
#define DEF_WW_UNIT_CAPTURED GC.getGameDefines().getWW_UNIT_CAPTURED()
#define DEF_ADVANCED_START_SIGHT_RANGE GC.getGameDefines().getADVANCED_START_SIGHT_RANGE()
#define DEF_BBAI_VICTORY_STRATEGY_DOMINATION GC.getGameDefines().getBBAI_VICTORY_STRATEGY_DOMINATION()
#define DEF_DISBANDING_EARNS_GOLD GC.getGameDefines().getDISBANDING_EARNS_GOLD()
#define DEF_TECH_DIFFUSION_WELFARE_THRESHOLD GC.getGameDefines().getTECH_DIFFUSION_WELFARE_THRESHOLD()
#define DEF_USE_CAN_DO_RESEARCH_CALLBACK GC.getGameDefines().getUSE_CAN_DO_RESEARCH_CALLBACK()
#define DEF_BBAI_VICTORY_STRATEGY_DIPLOMACY GC.getGameDefines().getBBAI_VICTORY_STRATEGY_DIPLOMACY()
#define DEF_BUG_CITYBAR_GREAT_PERSON_TURNS GC.getGameDefines().getBUG_CITYBAR_GREAT_PERSON_TURNS()
#define DEF_MIN_BARBARIAN_STARTING_DISTANCE GC.getGameDefines().getMIN_BARBARIAN_STARTING_DISTANCE()
#define DEF_SEAWATER_SEE_FROM_CHANGE GC.getGameDefines().getSEAWATER_SEE_FROM_CHANGE()
#define DEF_UPSCALED_RESEARCH_COST_MODIFIER GC.getGameDefines().getUPSCALED_RESEARCH_COST_MODIFIER()
#define DEF_USE_CAN_DO_RELIGION_CALLBACK GC.getGameDefines().getUSE_CAN_DO_RELIGION_CALLBACK()
#define DEF_CITY_BARBARIAN_DEFENSE_MODIFIER GC.getGameDefines().getCITY_BARBARIAN_DEFENSE_MODIFIER()
#define DEF_MAX_WORLD_WONDERS_PER_CITY GC.getGameDefines().getMAX_WORLD_WONDERS_PER_CITY()
#define DEF_PAGE_IN_DIST_UNIT GC.getGameDefines().getPAGE_IN_DIST_UNIT()
#define DEF_STANDARD_ERA GC.getGameDefines().getSTANDARD_ERA()
#define DEF_BASE_CAPTURE_GOLD GC.getGameDefines().getBASE_CAPTURE_GOLD()
#define DEF_HILLS_SEE_FROM_CHANGE GC.getGameDefines().getHILLS_SEE_FROM_CHANGE()
#define DEF_LAND_IMPROVEMENT GC.getGameDefines().getLAND_IMPROVEMENT()
#define DEF_MAX_BATTLE_TURNS GC.getGameDefines().getMAX_BATTLE_TURNS()
#define DEF_SHOW_HIDDEN_ATTITUDE GC.getGameDefines().getSHOW_HIDDEN_ATTITUDE()
#define DEF_WAR_SUCCESS_UNIT_CAPTURING GC.getGameDefines().getWAR_SUCCESS_UNIT_CAPTURING()
#define DEF_BASE_OCCUPATION_TURNS GC.getGameDefines().getBASE_OCCUPATION_TURNS()
#define DEF_GREAT_GENERALS_THRESHOLD_INCREASE_TEAM GC.getGameDefines().getGREAT_GENERALS_THRESHOLD_INCREASE_TEAM()
#define DEF_BUG_CONSCRIPT_UNIT_HOVER GC.getGameDefines().getBUG_CONSCRIPT_UNIT_HOVER()
#define DEF_CURSOR_SIZENE GC.getGameDefines().getCURSOR_SIZENE()
#define DEF_ESPIONAGE_CULTURE_MULTIPLIER_MOD GC.getGameDefines().getESPIONAGE_CULTURE_MULTIPLIER_MOD()
#define DEF_ESPIONAGE_SPY_REVEAL_IDENTITY_PERCENT GC.getGameDefines().getESPIONAGE_SPY_REVEAL_IDENTITY_PERCENT()
#define DEF_GREAT_PEOPLE_THRESHOLD_INCREASE GC.getGameDefines().getGREAT_PEOPLE_THRESHOLD_INCREASE()
#define DEF_IDW_PILLAGE_INFLUENCE_ENABLED GC.getGameDefines().getIDW_PILLAGE_INFLUENCE_ENABLED()
#define DEF_INITIAL_BASE_FREE_MILITARY_UNITS GC.getGameDefines().getINITIAL_BASE_FREE_MILITARY_UNITS()
#define DEF_INITIAL_GOLD_PER_UNIT GC.getGameDefines().getINITIAL_GOLD_PER_UNIT()
#define DEF_NUKE_BUILDING_DESTRUCTION_PROB GC.getGameDefines().getNUKE_BUILDING_DESTRUCTION_PROB()
#define DEF_NUKE_FALLOUT_PROB GC.getGameDefines().getNUKE_FALLOUT_PROB()
#define DEF_NUM_AND_TECH_PREREQS GC.getGameDefines().getNUM_AND_TECH_PREREQS()
#define DEF_REVOLT_TEST_PROB GC.getGameDefines().getREVOLT_TEST_PROB()
#define DEF_USE_CANNOT_FOUND_CITY_CALLBACK GC.getGameDefines().getUSE_CANNOT_FOUND_CITY_CALLBACK()
#define DEF_BARBARIAN_HANDICAP GC.getGameDefines().getBARBARIAN_HANDICAP()
#define DEF_BATTLE_EFFECT_LESS_COMMERCE GC.getGameDefines().getBATTLE_EFFECT_LESS_COMMERCE()
#define DEF_BBAI_HUMAN_AS_VASSAL_OPTION GC.getGameDefines().getBBAI_HUMAN_AS_VASSAL_OPTION()
#define DEF_BUG_BONUS_TRADE_DENIAL_HOVER GC.getGameDefines().getBUG_BONUS_TRADE_DENIAL_HOVER()
#define DEF_RELIGION_SPREAD_RAND GC.getGameDefines().getRELIGION_SPREAD_RAND()
#define DEF_COLD_FEATURE GC.getGameDefines().getCOLD_FEATURE()
#define DEF_HILLS_SEE_THROUGH_CHANGE GC.getGameDefines().getHILLS_SEE_THROUGH_CHANGE()
#define DEF_HOLYCITY_REMOVAL_GOLD GC.getGameDefines().getHOLYCITY_REMOVAL_GOLD()
#define DEF_OC_MIN_REV_INDEX GC.getGameDefines().getOC_MIN_REV_INDEX()
#define DEF_USE_CAN_DO_CIVIC_CALLBACK GC.getGameDefines().getUSE_CAN_DO_CIVIC_CALLBACK()
#define DEF_USE_FINISH_TEXT_CALLBACK GC.getGameDefines().getUSE_FINISH_TEXT_CALLBACK()
#define DEF_USE_SPIES_NO_ENTER_BORDERS GC.getGameDefines().getUSE_SPIES_NO_ENTER_BORDERS()
#define DEF_ACO_IGNORE_BARB_FREE_WINS GC.getGameDefines().getACO_IGNORE_BARB_FREE_WINS()
#define DEF_AGGRESSIVE_ANIMAL_LEADER GC.getGameDefines().getAGGRESSIVE_ANIMAL_LEADER()
#define DEF_BUG_CITYBAR_HURRY_ASSIST GC.getGameDefines().getBUG_CITYBAR_HURRY_ASSIST()
#define DEF_CAN_TRADE_EMBASSIES GC.getGameDefines().getCAN_TRADE_EMBASSIES()
#define DEF_FREE_VASSAL_POPULATION_PERCENT GC.getGameDefines().getFREE_VASSAL_POPULATION_PERCENT()
#define DEF_USE_CAN_BUILD_CALLBACK GC.getGameDefines().getUSE_CAN_BUILD_CALLBACK()
#define DEF_SCORE_VICTORY_PERCENT GC.getGameDefines().getSCORE_VICTORY_PERCENT()
#define DEF_USE_IS_PLAYER_RESEARCH_CALLBACK GC.getGameDefines().getUSE_IS_PLAYER_RESEARCH_CALLBACK()
#define DEF_DIPLOMACY_VALUE_REMAINDER GC.getGameDefines().getDIPLOMACY_VALUE_REMAINDER()
#define DEF_BUG_CITYBAR_HEALTH GC.getGameDefines().getBUG_CITYBAR_HEALTH()
#define DEF_DEFY_RESOLUTION_POP_ANGER GC.getGameDefines().getDEFY_RESOLUTION_POP_ANGER()
#define DEF_MAX_BOMBARD_DEFENSE GC.getGameDefines().getMAX_BOMBARD_DEFENSE()
#define DEF_MAX_YIELD_STACK GC.getGameDefines().getMAX_YIELD_STACK()
#define DEF_GREAT_GENERALS_THRESHOLD GC.getGameDefines().getGREAT_GENERALS_THRESHOLD()
#define DEF_LAND_TERRAIN GC.getGameDefines().getLAND_TERRAIN()
#define DEF_CITY_FREE_CULTURE_GROWTH_FACTOR GC.getGameDefines().getCITY_FREE_CULTURE_GROWTH_FACTOR()
#define DEF_CITY_THIRD_RING_EXTRA_GROWTH_THRESHOLD_PERCENT GC.getGameDefines().getCITY_THIRD_RING_EXTRA_GROWTH_THRESHOLD_PERCENT()
#define DEF_BASE_FEATURE_PRODUCTION_PERCENT GC.getGameDefines().getBASE_FEATURE_PRODUCTION_PERCENT()
#define DEF_BUG_LEADERHEAD_HOVER_HIDDEN_ATTITUDE GC.getGameDefines().getBUG_LEADERHEAD_HOVER_HIDDEN_ATTITUDE()
#define DEF_COLD_TERRAIN GC.getGameDefines().getCOLD_TERRAIN()
#define DEF_CURSOR_PARADROP GC.getGameDefines().getCURSOR_PARADROP()
#define DEF_DCM_FIGHTER_ENGAGE GC.getGameDefines().getDCM_FIGHTER_ENGAGE()
#define DEF_FORCE_UNOWNED_CITY_TIMER GC.getGameDefines().getFORCE_UNOWNED_CITY_TIMER()
#define DEF_RANGE_COMBAT_DAMAGE GC.getGameDefines().getRANGE_COMBAT_DAMAGE()
#define DEF_BUG_CDA_ZOOM_CITY_DETAILS GC.getGameDefines().getBUG_CDA_ZOOM_CITY_DETAILS()
#define DEF_BUG_HURRY_OVERFLOW_HOVER GC.getGameDefines().getBUG_HURRY_OVERFLOW_HOVER()
#define DEF_ACO_DEBUG GC.getGameDefines().getACO_DEBUG()
#define DEF_CONSCRIPT_POP_ANGER GC.getGameDefines().getCONSCRIPT_POP_ANGER()
#define DEF_FREE_VASSAL_LAND_PERCENT GC.getGameDefines().getFREE_VASSAL_LAND_PERCENT()
#define DEF_HILLS_EXTRA_DEFENSE GC.getGameDefines().getHILLS_EXTRA_DEFENSE()
#define DEF_UNIT_GOLD_DISBAND_DIVISOR GC.getGameDefines().getUNIT_GOLD_DISBAND_DIVISOR()
#define DEF_USE_AI_CAN_DO_WARPLANS_CALLBACK GC.getGameDefines().getUSE_AI_CAN_DO_WARPLANS_CALLBACK()
#define DEF_XML_LOGGING_ENABLED GC.getGameDefines().getXML_LOGGING_ENABLED()
#define DEF_PEAK_BUILD_TIME_MODIFIER GC.getGameDefines().getPEAK_BUILD_TIME_MODIFIER()
#define DEF_UPKEEP_POPULATION_OFFSET GC.getGameDefines().getUPKEEP_POPULATION_OFFSET()
#define DEF_CIV4_VERSION GC.getGameDefines().getCIV4_VERSION()
#define DEF_TECH_COST_KNOWN_PREREQ_MODIFIER GC.getGameDefines().getTECH_COST_KNOWN_PREREQ_MODIFIER()
#define DEF_BBAI_VICTORY_STRATEGY_CONQUEST GC.getGameDefines().getBBAI_VICTORY_STRATEGY_CONQUEST()
#define DEF_BUG_UPDATE_UNIT_NAME_ON_UPGRADE GC.getGameDefines().getBUG_UPDATE_UNIT_NAME_ON_UPGRADE()
#define DEF_DCM_ARCHER_BOMBARD GC.getGameDefines().getDCM_ARCHER_BOMBARD()
#define DEF_FOREIGN_TRADE_FULL_CREDIT_PEACE_TURNS GC.getGameDefines().getFOREIGN_TRADE_FULL_CREDIT_PEACE_TURNS()
#define DEF_NO_MILITARY_PERCENT_ANGER GC.getGameDefines().getNO_MILITARY_PERCENT_ANGER()
#define DEF_USE_GET_CITY_FOUND_VALUE_CALLBACK GC.getGameDefines().getUSE_GET_CITY_FOUND_VALUE_CALLBACK()
#define DEF_ACO_SHOW_TOTAL_DEFENSE_MODIFIER GC.getGameDefines().getACO_SHOW_TOTAL_DEFENSE_MODIFIER()
#define DEF_BUG_CITYBAR_REVOLT_CHANCE GC.getGameDefines().getBUG_CITYBAR_REVOLT_CHANCE()
#define DEF_BUG_UNIT_EXPERIENCE_HOVER GC.getGameDefines().getBUG_UNIT_EXPERIENCE_HOVER()
#define DEF_EXPERIENCE_FROM_WITHDRAWL GC.getGameDefines().getEXPERIENCE_FROM_WITHDRAWL()
#define DEF_USE_CAN_FOUND_CITIES_ON_WATER_CALLBACK GC.getGameDefines().getUSE_CAN_FOUND_CITIES_ON_WATER_CALLBACK()
#define DEF_ACO_SHOW_MODIFIER_LABELS GC.getGameDefines().getACO_SHOW_MODIFIER_LABELS()
#define DEF_AGGRESSIVE_ANIMAL_CIVILIZATION GC.getGameDefines().getAGGRESSIVE_ANIMAL_CIVILIZATION()
#define DEF_MIN_EXPERIENCE_PER_COMBAT GC.getGameDefines().getMIN_EXPERIENCE_PER_COMBAT()
#define DEF_NUKE_FEATURE GC.getGameDefines().getNUKE_FEATURE()
#define DEF_BUG_GREAT_PEOPLE_RATE_BREAKDOWN_HOVER GC.getGameDefines().getBUG_GREAT_PEOPLE_RATE_BREAKDOWN_HOVER()
#define DEF_CAN_TRADE_RELIGIONS GC.getGameDefines().getCAN_TRADE_RELIGIONS()
#define DEF_ADVANCED_START_POPULATION_COST GC.getGameDefines().getADVANCED_START_POPULATION_COST()
#define DEF_CUT_LOSERS_TURN_INCREMENT GC.getGameDefines().getCUT_LOSERS_TURN_INCREMENT()
#define DEF_NUKE_NON_COMBAT_DEATH_THRESHOLD GC.getGameDefines().getNUKE_NON_COMBAT_DEATH_THRESHOLD()
#define DEF_ADVANCED_START_VISIBILITY_COST GC.getGameDefines().getADVANCED_START_VISIBILITY_COST()
#define DEF_BUG_PRECHOP_FORESTS GC.getGameDefines().getBUG_PRECHOP_FORESTS()
#define DEF_INITIAL_FREE_MILITARY_UNITS_POPULATION_PERCENT GC.getGameDefines().getINITIAL_FREE_MILITARY_UNITS_POPULATION_PERCENT()
#define DEF_USE_CANNOT_TRAIN_CALLBACK GC.getGameDefines().getUSE_CANNOT_TRAIN_CALLBACK()
#define DEF_FRESH_WATER_HEALTH_CHANGE GC.getGameDefines().getFRESH_WATER_HEALTH_CHANGE()
#define DEF_RENDER_WATER GC.getGameDefines().getRENDER_WATER()
#define DEF_WARM_FEATURE GC.getGameDefines().getWARM_FEATURE()
#define DEF_BONUS_COUNT_PERCENTAGE_MODIFIER_ON_MORE_RESOURCES GC.getGameDefines().getBONUS_COUNT_PERCENTAGE_MODIFIER_ON_MORE_RESOURCES()
#define DEF_NUM_BUILDING_PREREQ_OR_BONUSES GC.getGameDefines().getNUM_BUILDING_PREREQ_OR_BONUSES()
#define DEF_OUR_POPULATION_TRADE_MODIFIER_OFFSET GC.getGameDefines().getOUR_POPULATION_TRADE_MODIFIER_OFFSET()
#define DEF_REVOLT_OCCUPATION_TURNS_PERCENT GC.getGameDefines().getREVOLT_OCCUPATION_TURNS_PERCENT()
#define DEF_TECH_DIFFUSION_WELFARE_MODIFIER GC.getGameDefines().getTECH_DIFFUSION_WELFARE_MODIFIER()
#define DEF_CAPTURE_GOLD_RAND1 GC.getGameDefines().getCAPTURE_GOLD_RAND1()
#define DEF_CAPTURE_GOLD_RAND2 GC.getGameDefines().getCAPTURE_GOLD_RAND2()
#define DEF_COLONY_NUM_FREE_DEFENDERS GC.getGameDefines().getCOLONY_NUM_FREE_DEFENDERS()
#define DEF_STANDARD_GAMESPEED GC.getGameDefines().getSTANDARD_GAMESPEED()
#define DEF_THEIR_POPULATION_TRADE_PERCENT GC.getGameDefines().getTHEIR_POPULATION_TRADE_PERCENT()
#define DEF_EVENT_MESSAGE_TIME GC.getGameDefines().getEVENT_MESSAGE_TIME()
#define DEF_SEA_ANIMAL_SPAWN_MODIFIER GC.getGameDefines().getSEA_ANIMAL_SPAWN_MODIFIER()
#define DEF_ESPIONAGE_CITY_TRADE_ROUTE_MOD GC.getGameDefines().getESPIONAGE_CITY_TRADE_ROUTE_MOD()
#define DEF_INITIAL_NON_STATE_RELIGION_HAPPINESS GC.getGameDefines().getINITIAL_NON_STATE_RELIGION_HAPPINESS()
#define DEF_UPGRADE_ROUND_LIMIT GC.getGameDefines().getUPGRADE_ROUND_LIMIT()
#define DEF_VASSAL_REVOLT_OWN_LOSSES_FACTOR GC.getGameDefines().getVASSAL_REVOLT_OWN_LOSSES_FACTOR()
#define DEF_DCM_OPP_FIRE GC.getGameDefines().getDCM_OPP_FIRE()
#define DEF_SCORE_FREE_PERCENT GC.getGameDefines().getSCORE_FREE_PERCENT()
#define DEF_CAN_TRADE_RESOURCES GC.getGameDefines().getCAN_TRADE_RESOURCES()
#define DEF_MAX_EXPERIENCE_PER_COMBAT GC.getGameDefines().getMAX_EXPERIENCE_PER_COMBAT()
#define DEF_WW_KILLED_UNIT_DEFENDING GC.getGameDefines().getWW_KILLED_UNIT_DEFENDING()
#define DEF_BUG_BUILDING_ADDITIONAL_HEALTH_HOVER GC.getGameDefines().getBUG_BUILDING_ADDITIONAL_HEALTH_HOVER()
#define DEF_ESPIONAGE_EACH_TURN_UNIT_COST_DECREASE GC.getGameDefines().getESPIONAGE_EACH_TURN_UNIT_COST_DECREASE()
#define DEF_ACO_SHOW_EXPERIENCE_RANGE GC.getGameDefines().getACO_SHOW_EXPERIENCE_RANGE()
#define DEF_GREAT_WORKS_CULTURE_TURNS GC.getGameDefines().getGREAT_WORKS_CULTURE_TURNS()
#define DEF_SPY_STEAL_PLANS_COST_MULTIPLIER GC.getGameDefines().getSPY_STEAL_PLANS_COST_MULTIPLIER()
#define DEF_NUM_UNIT_AND_TECH_PREREQS GC.getGameDefines().getNUM_UNIT_AND_TECH_PREREQS()
#define DEF_STARTING_DISTANCE_PERCENT GC.getGameDefines().getSTARTING_DISTANCE_PERCENT()
#define DEF_TREEHUGGER_DEFENSE_BONUS GC.getGameDefines().getTREEHUGGER_DEFENSE_BONUS()
#define DEF_DEEP_WATER_TERRAIN GC.getGameDefines().getDEEP_WATER_TERRAIN()
#define DEF_CORPORATION_FOREIGN_SPREAD_COST_PERCENT GC.getGameDefines().getCORPORATION_FOREIGN_SPREAD_COST_PERCENT()
#define DEF_FORTIFY_MODIFIER_PER_TURN GC.getGameDefines().getFORTIFY_MODIFIER_PER_TURN()
#define DEF_PEACE_TREATY_LENGTH GC.getGameDefines().getPEACE_TREATY_LENGTH()
#define DEF_WW_UNIT_KILLED_DEFENDING GC.getGameDefines().getWW_UNIT_KILLED_DEFENDING()
#define DEF_NUM_OR_TECH_PREREQS GC.getGameDefines().getNUM_OR_TECH_PREREQS()
#define DEF_SHIP_BLOCKADE_RANGE GC.getGameDefines().getSHIP_BLOCKADE_RANGE()
#define DEF_BUG_PRODUCTION_POPUP_TRAIN_MILITARY_UNITS_FOREVER GC.getGameDefines().getBUG_PRODUCTION_POPUP_TRAIN_MILITARY_UNITS_FOREVER()
#define DEF_DCM_BATTLE_EFFECTS GC.getGameDefines().getDCM_BATTLE_EFFECTS()
#define DEF_ESCAPE_MODIFIER_PER_TURN GC.getGameDefines().getESCAPE_MODIFIER_PER_TURN()
#define DEF_PATH_DAMAGE_WEIGHT GC.getGameDefines().getPATH_DAMAGE_WEIGHT()
#define DEF_DEFAULT_SPECIALIST GC.getGameDefines().getDEFAULT_SPECIALIST()
#define DEF_COMBAT_DAMAGE GC.getGameDefines().getCOMBAT_DAMAGE()
#define DEF_CURSOR_RECON GC.getGameDefines().getCURSOR_RECON()
#define DEF_FOUND_RELIGION_CITY_RAND GC.getGameDefines().getFOUND_RELIGION_CITY_RAND()
#define DEF_HURRY_POP_ANGER GC.getGameDefines().getHURRY_POP_ANGER()
#define DEF_MIN_CIV_STARTING_DISTANCE GC.getGameDefines().getMIN_CIV_STARTING_DISTANCE()
#define DEF_NEW_HURRY_MODIFIER GC.getGameDefines().getNEW_HURRY_MODIFIER()
#define DEF_SAVE_VERSION GC.getGameDefines().getSAVE_VERSION()
#define DEF_BUG_SENTRY_HEALING_ONLY_NEUTRAL GC.getGameDefines().getBUG_SENTRY_HEALING_ONLY_NEUTRAL()
#define DEF_INITIAL_FREE_UNITS_POPULATION_PERCENT GC.getGameDefines().getINITIAL_FREE_UNITS_POPULATION_PERCENT()
#define DEF_TECH_COST_MODIFIER GC.getGameDefines().getTECH_COST_MODIFIER()
#define DEF_BATTLE_EFFECTS_MINIMUM_TURN_INCREMENTS GC.getGameDefines().getBATTLE_EFFECTS_MINIMUM_TURN_INCREMENTS()
#define DEF_USE_ON_UNIT_LOST_CALLBACK GC.getGameDefines().getUSE_ON_UNIT_LOST_CALLBACK()
#define DEF_CANNOT_CLAIM_OCEAN GC.getGameDefines().getCANNOT_CLAIM_OCEAN()
#define DEF_FOOD_CONSUMPTION_PER_POPULATION GC.getGameDefines().getFOOD_CONSUMPTION_PER_POPULATION()
#define DEF_NEANDERTHAL_SPAWN_MODIFIER GC.getGameDefines().getNEANDERTHAL_SPAWN_MODIFIER()
#define DEF_DCM_ACTIVE_DEFENSE GC.getGameDefines().getDCM_ACTIVE_DEFENSE()
#define DEF_BUG_PRODUCTION_POPUP_TRAIN_CIVILIAN_UNITS_FOREVER GC.getGameDefines().getBUG_PRODUCTION_POPUP_TRAIN_CIVILIAN_UNITS_FOREVER()
#define DEF_TECH_COST_EXTRA_TEAM_MEMBER_MODIFIER GC.getGameDefines().getTECH_COST_EXTRA_TEAM_MEMBER_MODIFIER()
#define DEF_BUG_SENTRY_HEALING GC.getGameDefines().getBUG_SENTRY_HEALING()
#define DEF_DIRTY_POWER_HEALTH_CHANGE GC.getGameDefines().getDIRTY_POWER_HEALTH_CHANGE()
#define DEF_HURRY_ANGER_DIVISOR GC.getGameDefines().getHURRY_ANGER_DIVISOR()
#define DEF_NO_MILITARY_UNIT_TRADING GC.getGameDefines().getNO_MILITARY_UNIT_TRADING()
#define DEF_STANDARD_TURNTIMER GC.getGameDefines().getSTANDARD_TURNTIMER()
#define DEF_WW_KILLED_UNIT_ATTACKING GC.getGameDefines().getWW_KILLED_UNIT_ATTACKING()
#define DEF_FEATURE_PRODUCTION_PERCENT_MULTIPLIER GC.getGameDefines().getFEATURE_PRODUCTION_PERCENT_MULTIPLIER()
#define DEF_ANIMAL_MAX_XP_VALUE GC.getGameDefines().getANIMAL_MAX_XP_VALUE()
#define DEF_DCM_RB_CITYBOMBARD_CHANCE GC.getGameDefines().getDCM_RB_CITYBOMBARD_CHANCE()
#define DEF_USE_CANNOT_MAINTAIN_PROCESS_CALLBACK GC.getGameDefines().getUSE_CANNOT_MAINTAIN_PROCESS_CALLBACK()
#define DEF_BASE_RESEARCH_RATE GC.getGameDefines().getBASE_RESEARCH_RATE()
#define DEF_CAMERA_FORCE_TO_SMALLEST_MAX_DISTANCE GC.getGameDefines().getCAMERA_FORCE_TO_SMALLEST_MAX_DISTANCE()
#define DEF_DCM_ATTACK_SUPPORT GC.getGameDefines().getDCM_ATTACK_SUPPORT()
#define DEF_FRIENDLY_HEAL_RATE GC.getGameDefines().getFRIENDLY_HEAL_RATE()
#define DEF_MAX_UNIT_VISIBILITY_RANGE GC.getGameDefines().getMAX_UNIT_VISIBILITY_RANGE()
#define DEF_CURSOR_SIZEH GC.getGameDefines().getCURSOR_SIZEH()
#define DEF_ESPIONAGE_MISSION_COST_END_TOTAL_PERCENT_ADJUSTMENT GC.getGameDefines().getESPIONAGE_MISSION_COST_END_TOTAL_PERCENT_ADJUSTMENT()
#define DEF_PASSIVE_ANIMAL_CIVILIZATION GC.getGameDefines().getPASSIVE_ANIMAL_CIVILIZATION()
#define DEF_REVOLT_DEFENSE_STATE_RELIGION_MODIFIER GC.getGameDefines().getREVOLT_DEFENSE_STATE_RELIGION_MODIFIER()
#define DEF_REVOLT_OFFENSE_STATE_RELIGION_MODIFIER GC.getGameDefines().getREVOLT_OFFENSE_STATE_RELIGION_MODIFIER()
#define DEF_UPKEEP_CITY_OFFSET GC.getGameDefines().getUPKEEP_CITY_OFFSET()
#define DEF_BUG_CITYBAR_BUILDING_ICONS GC.getGameDefines().getBUG_CITYBAR_BUILDING_ICONS()
#define DEF_GAMEFONT_TGA_CORPORATIONS GC.getGameDefines().getGAMEFONT_TGA_CORPORATIONS()
#define DEF_MINIMUM_JUNGLE_SIZE GC.getGameDefines().getMINIMUM_JUNGLE_SIZE()
#define DEF_WW_UNIT_KILLED_ATTACKING GC.getGameDefines().getWW_UNIT_KILLED_ATTACKING()
#define DEF_CIRCUMNAVIGATE_FREE_MOVES GC.getGameDefines().getCIRCUMNAVIGATE_FREE_MOVES()
#define DEF_MAX_PAGING_FRAME_TIME_MS GC.getGameDefines().getMAX_PAGING_FRAME_TIME_MS()
#define DEF_REVOLT_FREE_UNITS_PERCENT GC.getGameDefines().getREVOLT_FREE_UNITS_PERCENT()
#define DEF_ESPIONAGE_SPY_NO_INTRUDE_INTERCEPT_MOD GC.getGameDefines().getESPIONAGE_SPY_NO_INTRUDE_INTERCEPT_MOD()
#define DEF_GLOBAL_WARMING_PROB GC.getGameDefines().getGLOBAL_WARMING_PROB()
#define DEF_IDW_EMERGENCY_DRAFT_ENABLED GC.getGameDefines().getIDW_EMERGENCY_DRAFT_ENABLED()
#define DEF_NUCLEAR_WINTER_PROB GC.getGameDefines().getNUCLEAR_WINTER_PROB()
#define DEF_MINIMAP_RENDER_SIZE GC.getGameDefines().getMINIMAP_RENDER_SIZE()
#define DEF_SCORE_WONDER_FACTOR GC.getGameDefines().getSCORE_WONDER_FACTOR()
#define DEF_ADVANCED_START_CITY_COST GC.getGameDefines().getADVANCED_START_CITY_COST()
#define DEF_MINIMUM_DESERT_SIZE GC.getGameDefines().getMINIMUM_DESERT_SIZE()
#define DEF_HOLY_CITY_INFLUENCE GC.getGameDefines().getHOLY_CITY_INFLUENCE()
#define DEF_USE_CAN_DO_COMBAT_CALLBACK GC.getGameDefines().getUSE_CAN_DO_COMBAT_CALLBACK()
#define DEF_ACO_SHOW_BASIC_INFO GC.getGameDefines().getACO_SHOW_BASIC_INFO()
#define DEF_MINIMUM_FOREST_SIZE GC.getGameDefines().getMINIMUM_FOREST_SIZE()
#define DEF_NUM_MOUNTAINS_NAMES GC.getGameDefines().getNUM_MOUNTAINS_NAMES()
#define DEF_NUM_WARNING_REVOLTS GC.getGameDefines().getNUM_WARNING_REVOLTS()
#define DEF_PAGE_IN_DIST_RIVER GC.getGameDefines().getPAGE_IN_DIST_RIVER()
#define DEF_RANGED_ATTACKS_USE_MOVES GC.getGameDefines().getRANGED_ATTACKS_USE_MOVES()
#define DEF_BARBARIAN_FREE_TECH_PERCENT GC.getGameDefines().getBARBARIAN_FREE_TECH_PERCENT()
#define DEF_BUG_CITYBAR_BASE_PRODUCTION GC.getGameDefines().getBUG_CITYBAR_BASE_PRODUCTION()
#define DEF_MAX_TEAM_WONDERS_PER_CITY GC.getGameDefines().getMAX_TEAM_WONDERS_PER_CITY()
#define DEF_MORE_XP_TO_LEVEL_MODIFIER GC.getGameDefines().getMORE_XP_TO_LEVEL_MODIFIER()
#define DEF_POWER_HEALTH_CHANGE GC.getGameDefines().getPOWER_HEALTH_CHANGE()
#define DEF_BUG_CITYBAR_COMMERCE GC.getGameDefines().getBUG_CITYBAR_COMMERCE()
#define DEF_USE_CAN_CONSTRUCT_CALLBACK GC.getGameDefines().getUSE_CAN_CONSTRUCT_CALLBACK()
#define DEF_CURSOR_ROUTE_TO GC.getGameDefines().getCURSOR_ROUTE_TO()
#define DEF_CURSOR_SIZEV GC.getGameDefines().getCURSOR_SIZEV()
#define DEF_RIVER_SOURCE_MIN_SEAWATER_RANGE GC.getGameDefines().getRIVER_SOURCE_MIN_SEAWATER_RANGE()
#define DEF_UNIT_ANIM_PAGE_MAX GC.getGameDefines().getUNIT_ANIM_PAGE_MAX()
#define DEF_WORKER_TRADE_VALUE_PERCENT_ADJUSTMENT GC.getGameDefines().getWORKER_TRADE_VALUE_PERCENT_ADJUSTMENT()
#define DEF_MIN_BARBARIAN_CITY_STARTING_DISTANCE GC.getGameDefines().getMIN_BARBARIAN_CITY_STARTING_DISTANCE()
#define DEF_VIEWPORT_SIZE_X GC.getGameDefines().getVIEWPORT_SIZE_X()
#define DEF_EVENT_MESSAGE_STAGGER_TIME GC.getGameDefines().getEVENT_MESSAGE_STAGGER_TIME()
#define DEF_FOUND_CORPORATION_CITY_RAND GC.getGameDefines().getFOUND_CORPORATION_CITY_RAND()
#define DEF_PEAK_EXTRA_MOVEMENT GC.getGameDefines().getPEAK_EXTRA_MOVEMENT()
#define DEF_VIEWPORT_SIZE_Y GC.getGameDefines().getVIEWPORT_SIZE_Y()
#define DEF_IDW_FORT_CAPTURE_MULTIPLIER GC.getGameDefines().getIDW_FORT_CAPTURE_MULTIPLIER()
#define DEF_GAME_CITY_SIZE_LINMAP_AT_0 GC.getGameDefines().getGAME_CITY_SIZE_LINMAP_AT_0()
#define DEF_GAME_CITY_SIZE_LINMAP_AT_50 GC.getGameDefines().getGAME_CITY_SIZE_LINMAP_AT_50()
#define DEF_FLAG_OFFSET2_X GC.getGameDefines().getFLAG_OFFSET2_X()
#define DEF_UNIT_TRAIL_RESOLUTION GC.getGameDefines().getUNIT_TRAIL_RESOLUTION()
#define DEF_FLAG_OFFSET2_Y GC.getGameDefines().getFLAG_OFFSET2_Y()
#define DEF_CAMERA_START_DISTANCE GC.getGameDefines().getCAMERA_START_DISTANCE()
#define DEF_CAMERA_SMALLEST_MAX_DISTANCE GC.getGameDefines().getCAMERA_SMALLEST_MAX_DISTANCE()
#define DEF_IDW_EMERGENCY_DRAFT_STRENGTH GC.getGameDefines().getIDW_EMERGENCY_DRAFT_STRENGTH()
#define DEF_GAME_CITY_SIZE_EXP_MODIFIER GC.getGameDefines().getGAME_CITY_SIZE_EXP_MODIFIER()
#define DEF_CAMERA_MIN_YAW GC.getGameDefines().getCAMERA_MIN_YAW()
#define DEF_CAMERA_MAX_YAW GC.getGameDefines().getCAMERA_MAX_YAW()
#define DEF_FOW_MINIMAP_WAS_VISIBLE_COLOR GC.getGameDefines().getFOW_MINIMAP_WAS_VISIBLE_COLOR()
#define DEF_BONUS_SCALE GC.getGameDefines().getBONUS_SCALE()
#define DEF_IDW_WARLORD_MULTIPLIER GC.getGameDefines().getIDW_WARLORD_MULTIPLIER()
#define DEF_CAMERA_CITY_ZOOM_IN_DISTANCE GC.getGameDefines().getCAMERA_CITY_ZOOM_IN_DISTANCE()
#define DEF_CAMERA_MIN_DISTANCE GC.getGameDefines().getCAMERA_MIN_DISTANCE()
#define DEF_CAMERA_MAX_SCROLL_SPEED GC.getGameDefines().getCAMERA_MAX_SCROLL_SPEED()
#define DEF_PLOT_SIZE GC.getGameDefines().getPLOT_SIZE()
#define DEF_IMPROVEMENT_SCALE GC.getGameDefines().getIMPROVEMENT_SCALE()
#define DEF_AIR_DEFEND_FINISH GC.getGameDefines().getAIR_DEFEND_FINISH()
#define DEF_CAMERA_MAX_TURN_OFFSET GC.getGameDefines().getCAMERA_MAX_TURN_OFFSET()
#define DEF_CAMERA_MIN_SCROLL_SPEED GC.getGameDefines().getCAMERA_MIN_SCROLL_SPEED()
#define DEF_CAMERA_NEAR_FAR_PLANE_RATIO GC.getGameDefines().getCAMERA_NEAR_FAR_PLANE_RATIO()
#define DEF_AIR_PATROL_RADIUS GC.getGameDefines().getAIR_PATROL_RADIUS()
#define DEF_CAMERA_MAX_TRAVEL_DISTANCE GC.getGameDefines().getCAMERA_MAX_TRAVEL_DISTANCE()
#define DEF_AIR_IDLE_HEIGHT GC.getGameDefines().getAIR_IDLE_HEIGHT()
#define DEF_AIR_PATROL_HEIGHT GC.getGameDefines().getAIR_PATROL_HEIGHT()
#define DEF_IDW_BASE_PILLAGE_INFLUENCE GC.getGameDefines().getIDW_BASE_PILLAGE_INFLUENCE()
#define DEF_FIELD_OF_VIEW GC.getGameDefines().getFIELD_OF_VIEW()
#define DEF_AIR_BOMB_HEIGHT GC.getGameDefines().getAIR_BOMB_HEIGHT()
#define DEF_FLAG_OFFSET_X GC.getGameDefines().getFLAG_OFFSET_X()
#define DEF_FLAG_OFFSET_Y GC.getGameDefines().getFLAG_OFFSET_Y()
#define DEF_HEALTH_BAR_WIDTH GC.getGameDefines().getHEALTH_BAR_WIDTH()
#define DEF_AIR_PATROL_SPEED GC.getGameDefines().getAIR_PATROL_SPEED()
#define DEF_SINGLE_UNIT_GFX_EXTRA_SCALE GC.getGameDefines().getSINGLE_UNIT_GFX_EXTRA_SCALE()
#define DEF_IDW_WINNER_PLOT_MULTIPLIER GC.getGameDefines().getIDW_WINNER_PLOT_MULTIPLIER()
#define DEF_CAMERA_SPECIAL_PITCH GC.getGameDefines().getCAMERA_SPECIAL_PITCH()
#define DEF_GAME_CITY_SIZE_MAX_PERCENT_UNIQUE GC.getGameDefines().getGAME_CITY_SIZE_MAX_PERCENT_UNIQUE()
#define DEF_IDW_EXPERIENCE_FACTOR GC.getGameDefines().getIDW_EXPERIENCE_FACTOR()
#define DEF_FOW_WAS_VISIBLE_COLOR GC.getGameDefines().getFOW_WAS_VISIBLE_COLOR()
#define DEF_SAD_FACTOR_1 GC.getGameDefines().getSAD_FACTOR_1()
#define DEF_SAD_FACTOR_2 GC.getGameDefines().getSAD_FACTOR_2()
#define DEF_CAMERA_SHRINE_ZOOM_IN_DISTANCE GC.getGameDefines().getCAMERA_SHRINE_ZOOM_IN_DISTANCE()
#define DEF_SAD_FACTOR_3 GC.getGameDefines().getSAD_FACTOR_3()
#define DEF_CAMERA_CITY_TURN GC.getGameDefines().getCAMERA_CITY_TURN()
#define DEF_SAD_FACTOR_4 GC.getGameDefines().getSAD_FACTOR_4()
#define DEF_CAMERA_BATTLE_ZOOM_IN_DISTANCE GC.getGameDefines().getCAMERA_BATTLE_ZOOM_IN_DISTANCE()
#define DEF_SHADOW_SCALE GC.getGameDefines().getSHADOW_SCALE()
#define DEF_WASTAGE_GROWTH_FACTOR GC.getGameDefines().getWASTAGE_GROWTH_FACTOR()
#define DEF_IDW_CITY_TILE_MULTIPLIER GC.getGameDefines().getIDW_CITY_TILE_MULTIPLIER()
#define DEF_AIR_EXECUTE_FINISH GC.getGameDefines().getAIR_EXECUTE_FINISH()
#define DEF_IDW_PLOT_DISTANCE_FACTOR GC.getGameDefines().getIDW_PLOT_DISTANCE_FACTOR()
#define DEF_EFFECT_DEFAULT_SIZE GC.getGameDefines().getEFFECT_DEFAULT_SIZE()
#define DEF_IDW_BASE_COMBAT_INFLUENCE GC.getGameDefines().getIDW_BASE_COMBAT_INFLUENCE()
#define DEF_IDW_NO_CITY_DEFENDER_MULTIPLIER GC.getGameDefines().getIDW_NO_CITY_DEFENDER_MULTIPLIER()
#define DEF_CAMERA_FAR_CLIP_Z_HEIGHT GC.getGameDefines().getCAMERA_FAR_CLIP_Z_HEIGHT()
#define DEF_AIR_DEFEND_DISTANCE GC.getGameDefines().getAIR_DEFEND_DISTANCE()
#define DEF_IDW_EMERGENCY_DRAFT_ANGER_MULTIPLIER GC.getGameDefines().getIDW_EMERGENCY_DRAFT_ANGER_MULTIPLIER()
#define DEF_RIVER_Z_BIAS GC.getGameDefines().getRIVER_Z_BIAS()
#define DEF_CAMERA_LOWER_PITCH GC.getGameDefines().getCAMERA_LOWER_PITCH()
#define DEF_CAMERA_UPPER_PITCH GC.getGameDefines().getCAMERA_UPPER_PITCH()
#define DEF_ROUTE_Z_BIAS GC.getGameDefines().getROUTE_Z_BIAS()
#define DEF_IDW_LOSER_PLOT_MULTIPLIER GC.getGameDefines().getIDW_LOSER_PLOT_MULTIPLIER()
#define DEF_AIR_EXECUTE_DISTANCE GC.getGameDefines().getAIR_EXECUTE_DISTANCE()
#define DEF_UNIT_MULTISELECT_DISTANCE GC.getGameDefines().getUNIT_MULTISELECT_DISTANCE()
#define DEF_GAME_CITY_SIZE_METHOD GC.getGameDefines().getGAME_CITY_SIZE_METHOD()
#define DEF_C2C_VERSION GC.getGameDefines().getC2C_VERSION()
#define DEF_LEADERHEAD_RANDOM GC.getGameDefines().getLEADERHEAD_RANDOM()
#define DEF_LANGUAGE GC.getGameDefines().getLANGUAGE()
#define DEF_PROFILER_ALTERNATE_SAMPLE_SET_SOURCE GC.getGameDefines().getPROFILER_ALTERNATE_SAMPLE_SET_SOURCE()
#define DEF_QUICKSAVE GC.getGameDefines().getQUICKSAVE()
#define DEF_ENABLE_BACKGROUND_PROFILING GC.getGameDefines().getENABLE_BACKGROUND_PROFILING()
#define DEF_DONT_ESCORT_SUBDUED_SEA_ANIMAL GC.getGameDefines().getDONT_ESCORT_SUBDUED_SEA_ANIMAL()
#define DEF_DYNAMIC_GREAT_WALL GC.getGameDefines().getDYNAMIC_GREAT_WALL()
#define DEF_DONT_ESCORT_SUBDUED_LAND_ANIMAL GC.getGameDefines().getDONT_ESCORT_SUBDUED_LAND_ANIMAL()


#define INCLUDE_GAMEOPTION_ADVANCED_START
#define GAMEOPTION_ADVANCED_START GC.getGame().isOption("GAMEOPTION_ADVANCED_START")
#define INCLUDE_GAMEOPTION_NO_CITY_RAZING
#define GAMEOPTION_NO_CITY_RAZING GC.getGame().isOption("GAMEOPTION_NO_CITY_RAZING")
#define INCLUDE_GAMEOPTION_NO_CITY_FLIPPING
#define GAMEOPTION_NO_CITY_FLIPPING GC.getGame().isOption("GAMEOPTION_NO_CITY_FLIPPING")
#define INCLUDE_GAMEOPTION_FLIPPING_AFTER_CONQUEST
#define GAMEOPTION_FLIPPING_AFTER_CONQUEST GC.getGame().isOption("GAMEOPTION_FLIPPING_AFTER_CONQUEST")
#define INCLUDE_GAMEOPTION_NO_BARBARIANS
#define GAMEOPTION_NO_BARBARIANS GC.getGame().isOption("GAMEOPTION_NO_BARBARIANS")
#define INCLUDE_GAMEOPTION_RAGING_BARBARIANS
#define GAMEOPTION_RAGING_BARBARIANS GC.getGame().isOption("GAMEOPTION_RAGING_BARBARIANS")
#define INCLUDE_GAMEOPTION_AGGRESSIVE_AI
#define GAMEOPTION_AGGRESSIVE_AI GC.getGame().isOption("GAMEOPTION_AGGRESSIVE_AI")
#define INCLUDE_GAMEOPTION_LEAD_ANY_CIV
#define GAMEOPTION_LEAD_ANY_CIV GC.getGame().isOption("GAMEOPTION_LEAD_ANY_CIV")
#define INCLUDE_GAMEOPTION_RANDOM_PERSONALITIES
#define GAMEOPTION_RANDOM_PERSONALITIES GC.getGame().isOption("GAMEOPTION_RANDOM_PERSONALITIES")
#define INCLUDE_GAMEOPTION_PICK_RELIGION
#define GAMEOPTION_PICK_RELIGION GC.getGame().isOption("GAMEOPTION_PICK_RELIGION")
#define INCLUDE_GAMEOPTION_NO_TECH_TRADING
#define GAMEOPTION_NO_TECH_TRADING GC.getGame().isOption("GAMEOPTION_NO_TECH_TRADING")
#define INCLUDE_GAMEOPTION_NO_TECH_BROKERING
#define GAMEOPTION_NO_TECH_BROKERING GC.getGame().isOption("GAMEOPTION_NO_TECH_BROKERING")
#define INCLUDE_GAMEOPTION_PERMANENT_ALLIANCES
#define GAMEOPTION_PERMANENT_ALLIANCES GC.getGame().isOption("GAMEOPTION_PERMANENT_ALLIANCES")
#define INCLUDE_GAMEOPTION_ONE_CITY_CHALLENGE
#define GAMEOPTION_ONE_CITY_CHALLENGE GC.getGame().isOption("GAMEOPTION_ONE_CITY_CHALLENGE")
#define INCLUDE_GAMEOPTION_NEW_RANDOM_SEED
#define GAMEOPTION_NEW_RANDOM_SEED GC.getGame().isOption("GAMEOPTION_NEW_RANDOM_SEED")
#define INCLUDE_GAMEOPTION_LOCK_MODS
#define GAMEOPTION_LOCK_MODS GC.getGame().isOption("GAMEOPTION_LOCK_MODS")
#define INCLUDE_GAMEOPTION_COMPLETE_KILLS
#define GAMEOPTION_COMPLETE_KILLS GC.getGame().isOption("GAMEOPTION_COMPLETE_KILLS")
#define INCLUDE_GAMEOPTION_NO_VASSAL_STATES
#define GAMEOPTION_NO_VASSAL_STATES GC.getGame().isOption("GAMEOPTION_NO_VASSAL_STATES")
#define INCLUDE_GAMEOPTION_NO_GOODY_HUTS
#define GAMEOPTION_NO_GOODY_HUTS GC.getGame().isOption("GAMEOPTION_NO_GOODY_HUTS")
#define INCLUDE_GAMEOPTION_NO_EVENTS
#define GAMEOPTION_NO_EVENTS GC.getGame().isOption("GAMEOPTION_NO_EVENTS")
#define INCLUDE_GAMEOPTION_NO_ESPIONAGE
#define GAMEOPTION_NO_ESPIONAGE GC.getGame().isOption("GAMEOPTION_NO_ESPIONAGE")
#define INCLUDE_GAMEOPTION_BARBARIAN_WORLD
#define GAMEOPTION_BARBARIAN_WORLD GC.getGame().isOption("GAMEOPTION_BARBARIAN_WORLD")
#define INCLUDE_GAMEOPTION_NO_REVOLUTION
#define GAMEOPTION_NO_REVOLUTION GC.getGame().isOption("GAMEOPTION_NO_REVOLUTION")
#define INCLUDE_GAMEOPTION_LIMITED_RELIGIONS
#define GAMEOPTION_LIMITED_RELIGIONS GC.getGame().isOption("GAMEOPTION_LIMITED_RELIGIONS")
#define INCLUDE_GAMEOPTION_NO_INQUISITIONS
#define GAMEOPTION_NO_INQUISITIONS GC.getGame().isOption("GAMEOPTION_NO_INQUISITIONS")
#define INCLUDE_GAMEOPTION_NO_BARBARIAN_CIV
#define GAMEOPTION_NO_BARBARIAN_CIV GC.getGame().isOption("GAMEOPTION_NO_BARBARIAN_CIV")
#define INCLUDE_GAMEOPTION_NO_TECH_DIFFUSION
#define GAMEOPTION_NO_TECH_DIFFUSION GC.getGame().isOption("GAMEOPTION_NO_TECH_DIFFUSION")
#define INCLUDE_GAMEOPTION_START_AS_MINORS
#define GAMEOPTION_START_AS_MINORS GC.getGame().isOption("GAMEOPTION_START_AS_MINORS")
#define INCLUDE_GAMEOPTION_MOUNTAINS
#define GAMEOPTION_MOUNTAINS GC.getGame().isOption("GAMEOPTION_MOUNTAINS")
#define INCLUDE_GAMEOPTION_SAD
#define GAMEOPTION_SAD GC.getGame().isOption("GAMEOPTION_SAD")
#define INCLUDE_GAMEOPTION_ADVANCED_DIPLOMACY
#define GAMEOPTION_ADVANCED_DIPLOMACY GC.getGame().isOption("GAMEOPTION_ADVANCED_DIPLOMACY")
#define INCLUDE_GAMEOPTION_UNLIMITED_WONDERS
#define GAMEOPTION_UNLIMITED_WONDERS GC.getGame().isOption("GAMEOPTION_UNLIMITED_WONDERS")
#define INCLUDE_GAMEOPTION_BARBARIAN_GENERALS
#define GAMEOPTION_BARBARIAN_GENERALS GC.getGame().isOption("GAMEOPTION_BARBARIAN_GENERALS")
#define INCLUDE_GAMEOPTION_NO_ZOC
#define GAMEOPTION_NO_ZOC GC.getGame().isOption("GAMEOPTION_NO_ZOC")
#define INCLUDE_GAMEOPTION_ASSIMILATION
#define GAMEOPTION_ASSIMILATION GC.getGame().isOption("GAMEOPTION_ASSIMILATION")
#define INCLUDE_GAMEOPTION_CHALLENGE_CUT_LOSERS
#define GAMEOPTION_CHALLENGE_CUT_LOSERS GC.getGame().isOption("GAMEOPTION_CHALLENGE_CUT_LOSERS")
#define INCLUDE_GAMEOPTION_CHALLENGE_HIGH_TO_LOW
#define GAMEOPTION_CHALLENGE_HIGH_TO_LOW GC.getGame().isOption("GAMEOPTION_CHALLENGE_HIGH_TO_LOW")
#define INCLUDE_GAMEOPTION_CHALLENGE_INCREASING_DIFFICULTY
#define GAMEOPTION_CHALLENGE_INCREASING_DIFFICULTY GC.getGame().isOption("GAMEOPTION_CHALLENGE_INCREASING_DIFFICULTY")
#define INCLUDE_GAMEOPTION_RUTHLESS_AI
#define GAMEOPTION_RUTHLESS_AI GC.getGame().isOption("GAMEOPTION_RUTHLESS_AI")
#define INCLUDE_GAMEOPTION_GREAT_COMMANDERS
#define GAMEOPTION_GREAT_COMMANDERS GC.getGame().isOption("GAMEOPTION_GREAT_COMMANDERS")
#define INCLUDE_GAMEOPTION_CULTURALLY_LINKED_STARTS
#define GAMEOPTION_CULTURALLY_LINKED_STARTS GC.getGame().isOption("GAMEOPTION_CULTURALLY_LINKED_STARTS")
#define INCLUDE_GAMEOPTION_PERSONALIZED_MAP
#define GAMEOPTION_PERSONALIZED_MAP GC.getGame().isOption("GAMEOPTION_PERSONALIZED_MAP")
#define INCLUDE_GAMEOPTION_ADVANCED_ECONOMY
#define GAMEOPTION_ADVANCED_ECONOMY GC.getGame().isOption("GAMEOPTION_ADVANCED_ECONOMY")
#define INCLUDE_GAMEOPTION_REALISTIC_CULTURE_SPREAD
#define GAMEOPTION_REALISTIC_CULTURE_SPREAD GC.getGame().isOption("GAMEOPTION_REALISTIC_CULTURE_SPREAD")
#define INCLUDE_GAMEOPTION_LARGER_CITIES
#define GAMEOPTION_LARGER_CITIES GC.getGame().isOption("GAMEOPTION_LARGER_CITIES")
#define INCLUDE_GAMEOPTION_REALISTIC_CORPORATIONS
#define GAMEOPTION_REALISTIC_CORPORATIONS GC.getGame().isOption("GAMEOPTION_REALISTIC_CORPORATIONS")
#define INCLUDE_GAMEOPTION_RELIGION_DECAY
#define GAMEOPTION_RELIGION_DECAY GC.getGame().isOption("GAMEOPTION_RELIGION_DECAY")
#define INCLUDE_GAMEOPTION_NO_FUTURE
#define GAMEOPTION_NO_FUTURE GC.getGame().isOption("GAMEOPTION_NO_FUTURE")
#define INCLUDE_GAMEOPTION_BARBARIANS_ALWAYS_RAZE
#define GAMEOPTION_BARBARIANS_ALWAYS_RAZE GC.getGame().isOption("GAMEOPTION_BARBARIANS_ALWAYS_RAZE")
#define INCLUDE_GAMEOPTION_UNITED_NATIONS
#define GAMEOPTION_UNITED_NATIONS GC.getGame().isOption("GAMEOPTION_UNITED_NATIONS")
#define INCLUDE_GAMEOPTION_ADVANCED_ESPIONAGE
#define GAMEOPTION_ADVANCED_ESPIONAGE GC.getGame().isOption("GAMEOPTION_ADVANCED_ESPIONAGE")
#define INCLUDE_GAMEOPTION_ADVANCED_NUKES
#define GAMEOPTION_ADVANCED_NUKES GC.getGame().isOption("GAMEOPTION_ADVANCED_NUKES")
#define INCLUDE_GAMEOPTION_DIVINE_PROPHETS
#define GAMEOPTION_DIVINE_PROPHETS GC.getGame().isOption("GAMEOPTION_DIVINE_PROPHETS")
#define INCLUDE_GAMEOPTION_NO_CITY_LIMITS
#define GAMEOPTION_NO_CITY_LIMITS GC.getGame().isOption("GAMEOPTION_NO_CITY_LIMITS")
#define INCLUDE_GAMEOPTION_NO_FIXED_BORDERS
#define GAMEOPTION_NO_FIXED_BORDERS GC.getGame().isOption("GAMEOPTION_NO_FIXED_BORDERS")
#define INCLUDE_GAMEOPTION_INFINITE_XP
#define GAMEOPTION_INFINITE_XP GC.getGame().isOption("GAMEOPTION_INFINITE_XP")
#define INCLUDE_GAMEOPTION_UNLIMITED_NATIONAL_UNITS
#define GAMEOPTION_UNLIMITED_NATIONAL_UNITS GC.getGame().isOption("GAMEOPTION_UNLIMITED_NATIONAL_UNITS")
#define INCLUDE_GAMEOPTION_STRENGTH_IN_NUMBERS
#define GAMEOPTION_STRENGTH_IN_NUMBERS GC.getGame().isOption("GAMEOPTION_STRENGTH_IN_NUMBERS")
#define INCLUDE_GAMEOPTION_NO_NEGATIVE_TRAITS
#define GAMEOPTION_NO_NEGATIVE_TRAITS GC.getGame().isOption("GAMEOPTION_NO_NEGATIVE_TRAITS")
#define INCLUDE_GAMEOPTION_PURE_TRAITS
#define GAMEOPTION_PURE_TRAITS GC.getGame().isOption("GAMEOPTION_PURE_TRAITS")
#define INCLUDE_GAMEOPTION_LEADERHEAD_LEVELUPS
#define GAMEOPTION_LEADERHEAD_LEVELUPS GC.getGame().isOption("GAMEOPTION_LEADERHEAD_LEVELUPS")
#define INCLUDE_GAMEOPTION_START_NO_POSITIVE_TRAITS
#define GAMEOPTION_START_NO_POSITIVE_TRAITS GC.getGame().isOption("GAMEOPTION_START_NO_POSITIVE_TRAITS")
#define INCLUDE_GAMEOPTION_NO_NUKES
#define GAMEOPTION_NO_NUKES GC.getGame().isOption("GAMEOPTION_NO_NUKES")
#define INCLUDE_GAMEOPTION_SCALE_CITY_LIMITS
#define GAMEOPTION_SCALE_CITY_LIMITS GC.getGame().isOption("GAMEOPTION_SCALE_CITY_LIMITS")
#define INCLUDE_GAMEOPTION_COMPLEX_TRAITS
#define GAMEOPTION_COMPLEX_TRAITS GC.getGame().isOption("GAMEOPTION_COMPLEX_TRAITS")
#define INCLUDE_GAMEOPTION_LS612_TRAITS
#define GAMEOPTION_LS612_TRAITS GC.getGame().isOption("GAMEOPTION_LS612_TRAITS")
#define INCLUDE_GAMEOPTION_RELIGIOUS_DISABLING
#define GAMEOPTION_RELIGIOUS_DISABLING GC.getGame().isOption("GAMEOPTION_RELIGIOUS_DISABLING")
#define INCLUDE_GAMEOPTION_UPSCALED_BUILDING_AND_UNIT_COSTS
#define GAMEOPTION_UPSCALED_BUILDING_AND_UNIT_COSTS GC.getGame().isOption("GAMEOPTION_UPSCALED_BUILDING_AND_UNIT_COSTS")
#define INCLUDE_GAMEOPTION_FIGHT_OR_FLIGHT
#define GAMEOPTION_FIGHT_OR_FLIGHT GC.getGame().isOption("GAMEOPTION_FIGHT_OR_FLIGHT")
#define INCLUDE_GAMEOPTION_SIZE_MATTERS
#define GAMEOPTION_SIZE_MATTERS GC.getGame().isOption("GAMEOPTION_SIZE_MATTERS")
#define INCLUDE_GAMEOPTION_HEART_OF_WAR
#define GAMEOPTION_HEART_OF_WAR GC.getGame().isOption("GAMEOPTION_HEART_OF_WAR")
#define INCLUDE_GAMEOPTION_BATTLEWORN
#define GAMEOPTION_BATTLEWORN GC.getGame().isOption("GAMEOPTION_BATTLEWORN")
#define INCLUDE_GAMEOPTION_UPRANGE
#define GAMEOPTION_UPRANGE GC.getGame().isOption("GAMEOPTION_UPRANGE")
#define INCLUDE_GAMEOPTION_EQUIPMENT
#define GAMEOPTION_EQUIPMENT GC.getGame().isOption("GAMEOPTION_EQUIPMENT")
#define INCLUDE_GAMEOPTION_MAXIMUM_POPULATION
#define GAMEOPTION_MAXIMUM_POPULATION GC.getGame().isOption("GAMEOPTION_MAXIMUM_POPULATION")
#define INCLUDE_GAMEOPTION_MIN_CITY_BORDER
#define GAMEOPTION_MIN_CITY_BORDER GC.getGame().isOption("GAMEOPTION_MIN_CITY_BORDER")
#define INCLUDE_GAMEOPTION_MORE_RIVERS
#define GAMEOPTION_MORE_RIVERS GC.getGame().isOption("GAMEOPTION_MORE_RIVERS")
#define INCLUDE_GAMEOPTION_MORE_RESOURCES
#define GAMEOPTION_MORE_RESOURCES GC.getGame().isOption("GAMEOPTION_MORE_RESOURCES")
#define INCLUDE_GAMEOPTION_XP_FROM_ASSIGNED_SPECIALISTS
#define GAMEOPTION_XP_FROM_ASSIGNED_SPECIALISTS GC.getGame().isOption("GAMEOPTION_XP_FROM_ASSIGNED_SPECIALISTS")
#define INCLUDE_GAMEOPTION_MORE_XP_TO_LEVEL
#define GAMEOPTION_MORE_XP_TO_LEVEL GC.getGame().isOption("GAMEOPTION_MORE_XP_TO_LEVEL")
#define INCLUDE_GAMEOPTION_ONGOING_TRAINING
#define GAMEOPTION_ONGOING_TRAINING GC.getGame().isOption("GAMEOPTION_ONGOING_TRAINING")
#define INCLUDE_GAMEOPTION_NIGHTMARE_MODE
#define GAMEOPTION_NIGHTMARE_MODE GC.getGame().isOption("GAMEOPTION_NIGHTMARE_MODE")
#define INCLUDE_GAMEOPTION_SIZE_MATTERS_UNCUT
#define GAMEOPTION_SIZE_MATTERS_UNCUT GC.getGame().isOption("GAMEOPTION_SIZE_MATTERS_UNCUT")
#define INCLUDE_GAMEOPTION_ECOLOGICAL_ANIMALS
#define GAMEOPTION_ECOLOGICAL_ANIMALS GC.getGame().isOption("GAMEOPTION_ECOLOGICAL_ANIMALS")
#define INCLUDE_GAMEOPTION_TELEPORT_HUNTING_AWARDS
#define GAMEOPTION_TELEPORT_HUNTING_AWARDS GC.getGame().isOption("GAMEOPTION_TELEPORT_HUNTING_AWARDS")
#define INCLUDE_GAMEOPTION_AMNESTY
#define GAMEOPTION_AMNESTY GC.getGame().isOption("GAMEOPTION_AMNESTY")
#define INCLUDE_GAMEOPTION_HIDE_AND_SEEK
#define GAMEOPTION_HIDE_AND_SEEK GC.getGame().isOption("GAMEOPTION_HIDE_AND_SEEK")
#define INCLUDE_GAMEOPTION_PEACE_AMONG_NPCS
#define GAMEOPTION_PEACE_AMONG_NPCS GC.getGame().isOption("GAMEOPTION_PEACE_AMONG_NPCS")
#define INCLUDE_GAMEOPTION_ANIMALS_STAY_OUT
#define GAMEOPTION_ANIMALS_STAY_OUT GC.getGame().isOption("GAMEOPTION_ANIMALS_STAY_OUT")
#define INCLUDE_GAMEOPTION_RECKLESS_ANIMALS
#define GAMEOPTION_RECKLESS_ANIMALS GC.getGame().isOption("GAMEOPTION_RECKLESS_ANIMALS")
#define INCLUDE_GAMEOPTION_NEANDERTHAL_CITIES
#define GAMEOPTION_NEANDERTHAL_CITIES GC.getGame().isOption("GAMEOPTION_NEANDERTHAL_CITIES")
#define INCLUDE_GAMEOPTION_1_CITY_TILE_FOUNDING
#define GAMEOPTION_1_CITY_TILE_FOUNDING GC.getGame().isOption("GAMEOPTION_1_CITY_TILE_FOUNDING")
#define INCLUDE_GAMEOPTION_REALISTIC_SIEGE
#define GAMEOPTION_REALISTIC_SIEGE GC.getGame().isOption("GAMEOPTION_REALISTIC_SIEGE")
#define INCLUDE_GAMEOPTION_VANILLA_COMBAT_ENGINE
#define GAMEOPTION_VANILLA_COMBAT_ENGINE GC.getGame().isOption("GAMEOPTION_VANILLA_COMBAT_ENGINE")
#define INCLUDE_GAMEOPTION_WITHOUT_WARNING
#define GAMEOPTION_WITHOUT_WARNING GC.getGame().isOption("GAMEOPTION_WITHOUT_WARNING")
#define INCLUDE_GAMEOPTION_WIN_FOR_LOSING
#define GAMEOPTION_WIN_FOR_LOSING GC.getGame().isOption("GAMEOPTION_WIN_FOR_LOSING")
#define INCLUDE_GAMEOPTION_BEELINE_STINGS
#define GAMEOPTION_BEELINE_STINGS GC.getGame().isOption("GAMEOPTION_BEELINE_STINGS")
#define INCLUDE_GAMEOPTION_OUTBREAKS_AND_AFFLICTIONS
#define GAMEOPTION_OUTBREAKS_AND_AFFLICTIONS GC.getGame().isOption("GAMEOPTION_OUTBREAKS_AND_AFFLICTIONS")
#define INCLUDE_GAMEOPTION_NO_TECH_HANDICAPS_FOR_HUMANS
#define GAMEOPTION_NO_TECH_HANDICAPS_FOR_HUMANS GC.getGame().isOption("GAMEOPTION_NO_TECH_HANDICAPS_FOR_HUMANS")
#define INCLUDE_GAMEOPTION_DOWNSIZING_IS_PROFITABLE
#define GAMEOPTION_DOWNSIZING_IS_PROFITABLE GC.getGame().isOption("GAMEOPTION_DOWNSIZING_IS_PROFITABLE")
#define INCLUDE_GAMEOPTION_UPSCALED_RESEARCH_COSTS
#define GAMEOPTION_UPSCALED_RESEARCH_COSTS GC.getGame().isOption("GAMEOPTION_UPSCALED_RESEARCH_COSTS")
#define INCLUDE_GAMEOPTION_DANGEROUS_WILDLIFE
#define GAMEOPTION_DANGEROUS_WILDLIFE GC.getGame().isOption("GAMEOPTION_DANGEROUS_WILDLIFE")
