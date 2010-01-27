/************************************************************
*
*	CyberLink for C
*
*	Copyright (C) Satoshi Konno 2005
*
*	File: cavtransport_service.c
*
*	Revision:
*		2009/06/11
*        - first release.
*
************************************************************/

#ifdef HAVE_CONFIG_H
#  include "config.h"
#endif

#include <cybergarage/upnp/std/av/cmediarenderer.h>

/****************************************
* Service Description (AVTransport)
****************************************/

static char *CG_UPNPAV_DMR_AVTRANSPORT_SERVICE_DESCRIPTION = 
"<?xml version=\"1.0\" encoding=\"utf-8\"?>\n"
"<scpd xmlns=\"urn:schemas-upnp-org:service-1-0\">\n"
"   <specVersion>\n"
"      <major>1</major>\n"
"      <minor>0</minor>\n"
"   </specVersion>\n"
"   <actionList>\n"
"      <action>\n"
"         <name>GetCurrentTransportActions</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>Actions</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>CurrentTransportActions</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>GetDeviceCapabilities</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>PlayMedia</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>PossiblePlaybackStorageMedia</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>RecMedia</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>PossibleRecordStorageMedia</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>RecQualityModes</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>PossibleRecordQualityModes</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>GetMediaInfo</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>NrTracks</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>NumberOfTracks</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>MediaDuration</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>CurrentMediaDuration</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>CurrentURI</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>AVTransportURI</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>CurrentURIMetaData</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>AVTransportURIMetaData</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>NextURI</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>NextAVTransportURI</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>NextURIMetaData</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>NextAVTransportURIMetaData</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>PlayMedium</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>PlaybackStorageMedium</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>RecordMedium</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>RecordStorageMedium</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>WriteStatus</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>RecordMediumWriteStatus</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>GetPositionInfo</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>Track</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>CurrentTrack</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>TrackDuration</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>CurrentTrackDuration</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>TrackMetaData</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>CurrentTrackMetaData</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>TrackURI</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>CurrentTrackURI</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>RelTime</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>RelativeTimePosition</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>AbsTime</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>AbsoluteTimePosition</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>RelCount</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>RelativeCounterPosition</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>AbsCount</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>AbsoluteCounterPosition</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>GetTransportInfo</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>CurrentTransportState</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>TransportState</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>CurrentTransportStatus</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>TransportStatus</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>CurrentSpeed</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>TransportPlaySpeed</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>GetTransportSettings</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>PlayMode</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>CurrentPlayMode</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>RecQualityMode</name>\n"
"               <direction>out</direction>\n"
"               <relatedStateVariable>CurrentRecordQualityMode</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>Next</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>Pause</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>Play</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>Speed</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>TransportPlaySpeed</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>Previous</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>Seek</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>Unit</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_SeekMode</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>Target</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_SeekTarget</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>SetAVTransportURI</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>CurrentURI</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>AVTransportURI</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>CurrentURIMetaData</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>AVTransportURIMetaData</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>SetPlayMode</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"            <argument>\n"
"               <name>NewPlayMode</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>CurrentPlayMode</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"      <action>\n"
"         <name>Stop</name>\n"
"         <argumentList>\n"
"            <argument>\n"
"               <name>InstanceID</name>\n"
"               <direction>in</direction>\n"
"               <relatedStateVariable>A_ARG_TYPE_InstanceID</relatedStateVariable>\n"
"            </argument>\n"
"         </argumentList>\n"
"      </action>\n"
"   </actionList>\n"
"   <serviceStateTable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>CurrentPlayMode</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>NORMAL</allowedValue>\n"
"            <allowedValue>REPEAT_ALL</allowedValue>\n"
"            <allowedValue>SHUFFLE</allowedValue>\n"
"         </allowedValueList>\n"
"         <defaultValue>NORMAL</defaultValue>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>RecordStorageMedium</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>UNKNOWN</allowedValue>\n"
"            <allowedValue>DV</allowedValue>\n"
"            <allowedValue>MINI-DV</allowedValue>\n"
"            <allowedValue>VHS</allowedValue>\n"
"            <allowedValue>W-VHS</allowedValue>\n"
"            <allowedValue>S-VHS</allowedValue>\n"
"            <allowedValue>D-VHS</allowedValue>\n"
"            <allowedValue>VHSC</allowedValue>\n"
"            <allowedValue>VIDEO8</allowedValue>\n"
"            <allowedValue>HI8</allowedValue>\n"
"            <allowedValue>CD-ROM</allowedValue>\n"
"            <allowedValue>CD-DA</allowedValue>\n"
"            <allowedValue>CD-R</allowedValue>\n"
"            <allowedValue>CD-RW</allowedValue>\n"
"            <allowedValue>VIDEO-CD</allowedValue>\n"
"            <allowedValue>SACD</allowedValue>\n"
"            <allowedValue>MD-AUDIO</allowedValue>\n"
"            <allowedValue>MD-PICTURE</allowedValue>\n"
"            <allowedValue>DVD-ROM</allowedValue>\n"
"            <allowedValue>DVD-VIDEO</allowedValue>\n"
"            <allowedValue>DVD-R</allowedValue>\n"
"            <allowedValue>DVD+RW</allowedValue>\n"
"            <allowedValue>DVD-RW</allowedValue>\n"
"            <allowedValue>DVD-RAM</allowedValue>\n"
"            <allowedValue>DVD-AUDIO</allowedValue>\n"
"            <allowedValue>DAT</allowedValue>\n"
"            <allowedValue>LD</allowedValue>\n"
"            <allowedValue>HDD</allowedValue>\n"
"            <allowedValue>MICRO-MV</allowedValue>\n"
"            <allowedValue>NETWORK</allowedValue>\n"
"            <allowedValue>NONE</allowedValue>\n"
"            <allowedValue>NOT_IMPLEMENTED</allowedValue>\n"
"            <allowedValue> vendor-defined </allowedValue>\n"
"         </allowedValueList>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"yes\">\n"
"         <name>LastChange</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>RelativeTimePosition</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>CurrentTrackURI</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>CurrentTrackDuration</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>CurrentRecordQualityMode</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>0:EP</allowedValue>\n"
"            <allowedValue>1:LP</allowedValue>\n"
"            <allowedValue>2:SP</allowedValue>\n"
"            <allowedValue>0:BASIC</allowedValue>\n"
"            <allowedValue>1:MEDIUM</allowedValue>\n"
"            <allowedValue>2:HIGH</allowedValue>\n"
"            <allowedValue>NOT_IMPLEMENTED</allowedValue>\n"
"            <allowedValue> vendor-defined </allowedValue>\n"
"         </allowedValueList>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>CurrentMediaDuration</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>AbsoluteCounterPosition</name>\n"
"         <dataType>i4</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>RelativeCounterPosition</name>\n"
"         <dataType>i4</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>A_ARG_TYPE_InstanceID</name>\n"
"         <dataType>ui4</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>AVTransportURI</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>TransportState</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>STOPPED</allowedValue>\n"
"            <allowedValue>PAUSED_PLAYBACK</allowedValue>\n"
"            <allowedValue>PAUSED_RECORDING</allowedValue>\n"
"            <allowedValue>PLAYING</allowedValue>\n"
"            <allowedValue>RECORDING</allowedValue>\n"
"            <allowedValue>TRANSITIONING</allowedValue>\n"
"            <allowedValue>NO_MEDIA_PRESENT</allowedValue>\n"
"         </allowedValueList>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>CurrentTrackMetaData</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>NextAVTransportURI</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>PossibleRecordQualityModes</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>CurrentTrack</name>\n"
"         <dataType>ui4</dataType>\n"
"         <allowedValueRange>\n"
"            <minimum>0</minimum>\n"
"            <maximum>4294967295</maximum>\n"
"            <step>1</step>\n"
"         </allowedValueRange>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>AbsoluteTimePosition</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>NextAVTransportURIMetaData</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>PlaybackStorageMedium</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>UNKNOWN</allowedValue>\n"
"            <allowedValue>DV</allowedValue>\n"
"            <allowedValue>MINI-DV</allowedValue>\n"
"            <allowedValue>VHS</allowedValue>\n"
"            <allowedValue>W-VHS</allowedValue>\n"
"            <allowedValue>S-VHS</allowedValue>\n"
"            <allowedValue>D-VHS</allowedValue>\n"
"            <allowedValue>VHSC</allowedValue>\n"
"            <allowedValue>VIDEO8</allowedValue>\n"
"            <allowedValue>HI8</allowedValue>\n"
"            <allowedValue>CD-ROM</allowedValue>\n"
"            <allowedValue>CD-DA</allowedValue>\n"
"            <allowedValue>CD-R</allowedValue>\n"
"            <allowedValue>CD-RW</allowedValue>\n"
"            <allowedValue>VIDEO-CD</allowedValue>\n"
"            <allowedValue>SACD</allowedValue>\n"
"            <allowedValue>MD-AUDIO</allowedValue>\n"
"            <allowedValue>MD-PICTURE</allowedValue>\n"
"            <allowedValue>DVD-ROM</allowedValue>\n"
"            <allowedValue>DVD-VIDEO</allowedValue>\n"
"            <allowedValue>DVD-R</allowedValue>\n"
"            <allowedValue>DVD+RW</allowedValue>\n"
"            <allowedValue>DVD-RW</allowedValue>\n"
"            <allowedValue>DVD-RAM</allowedValue>\n"
"            <allowedValue>DVD-AUDIO</allowedValue>\n"
"            <allowedValue>DAT</allowedValue>\n"
"            <allowedValue>LD</allowedValue>\n"
"            <allowedValue>HDD</allowedValue>\n"
"            <allowedValue>MICRO-MV</allowedValue>\n"
"            <allowedValue>NETWORK</allowedValue>\n"
"            <allowedValue>NONE</allowedValue>\n"
"            <allowedValue>NOT_IMPLEMENTED</allowedValue>\n"
"            <allowedValue> vendor-defined </allowedValue>\n"
"         </allowedValueList>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>CurrentTransportActions</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>RecordMediumWriteStatus</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>WRITABLE</allowedValue>\n"
"            <allowedValue>PROTECTED</allowedValue>\n"
"            <allowedValue>NOT_WRITABLE</allowedValue>\n"
"            <allowedValue>UNKNOWN</allowedValue>\n"
"            <allowedValue>NOT_IMPLEMENTED</allowedValue>\n"
"         </allowedValueList>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>PossiblePlaybackStorageMedia</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>AVTransportURIMetaData</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>NumberOfTracks</name>\n"
"         <dataType>ui4</dataType>\n"
"         <allowedValueRange>\n"
"            <minimum>0</minimum>\n"
"            <maximum>4294967295</maximum>\n"
"         </allowedValueRange>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>A_ARG_TYPE_SeekMode</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>TRACK_NR</allowedValue>\n"
"            <allowedValue>REL_TIME</allowedValue>\n"
"         </allowedValueList>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>A_ARG_TYPE_SeekTarget</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>PossibleRecordStorageMedia</name>\n"
"         <dataType>string</dataType>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>TransportStatus</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>OK</allowedValue>\n"
"            <allowedValue>ERROR_OCCURRED</allowedValue>\n"
"            <allowedValue> vendor-defined </allowedValue>\n"
"         </allowedValueList>\n"
"      </stateVariable>\n"
"      <stateVariable sendEvents=\"no\">\n"
"         <name>TransportPlaySpeed</name>\n"
"         <dataType>string</dataType>\n"
"         <allowedValueList>\n"
"            <allowedValue>1</allowedValue>\n"
"            <allowedValue> vendor-defined </allowedValue>\n"
"         </allowedValueList>\n"
"      </stateVariable>\n"
"   </serviceStateTable>\n"
"</scpd>\n";

/****************************************
* cg_upnpav_dmr_avtransport_actionreceived
****************************************/

BOOL cg_upnpav_dmr_avtransport_actionreceived(CgUpnpAction *action)
{
	CgUpnpAvRenderer *dmr;
	CgUpnpDevice *dev;
	char *actionName;
	CgUpnpArgument *arg;

	actionName = cg_upnp_action_getname(action);
	if (cg_strlen(actionName) <= 0)
		return FALSE;

	dev = (CgUpnpDevice *)cg_upnp_service_getdevice(cg_upnp_action_getservice(action));
	if (!dev) 
		return FALSE;

	dmr = (CgUpnpAvRenderer *)cg_upnp_device_getuserdata(dev);
	if (!dmr)
		return FALSE;
	
	/* GetTransportInfo*/
	if (cg_streq(actionName, CG_UPNPAV_DMR_AVTRANSPORT_GETTRANSPORTINFO)) {
		arg = cg_upnp_action_getargumentbyname(action, CG_UPNPAV_DMR_AVTRANSPORT_CURRENTTRANSPORTSTATE);
		if (!arg)
			return FALSE;
		cg_upnp_argument_setvalue(arg, CG_UPNPAV_DMR_AVTRANSPORT_CURRENTTRANSPORTSTATE_NOMEDIAPRESENT);

		arg = cg_upnp_action_getargumentbyname(action, CG_UPNPAV_DMR_AVTRANSPORT_CURRENTTRANSPORTSTATUS);
		if (!arg)
			return FALSE;
		cg_upnp_argument_setvalue(arg, CG_UPNPAV_DMR_AVTRANSPORT_CURRENTTRANSPORTSTATUS_OK);
		
		arg = cg_upnp_action_getargumentbyname(action, CG_UPNPAV_DMR_AVTRANSPORT_CURRENTSPEED);
		if (!arg)
			return FALSE;
		cg_upnp_argument_setvalue(arg, "1");
		return TRUE;
	}
	
	return FALSE;
}

/****************************************
 * cg_upnpav_dmr_avtransport_queryreceived
 ****************************************/

BOOL cg_upnpav_dmr_avtransport_queryreceived(CgUpnpStateVariable *statVar)
{
	return FALSE;
}

/****************************************
* cg_upnpav_dmr_avtransport_init
****************************************/

BOOL cg_upnpav_dmr_avtransport_init(CgUpnpAvRenderer *dmr)
{
	CgUpnpDevice *dev;
	CgUpnpService *service;
	CgUpnpAction *action;

	dev = cg_upnpav_dmr_getdevice(dmr);
	if (!dev)
		return FALSE;

	service = cg_upnp_device_getservicebytype(dev, CG_UPNPAV_DMR_AVTRANSPORT_SERVICE_TYPE);
	if (!service)
		return FALSE;
	
	if (cg_upnp_service_parsedescription(service, CG_UPNPAV_DMR_AVTRANSPORT_SERVICE_DESCRIPTION, cg_strlen(CG_UPNPAV_DMR_AVTRANSPORT_SERVICE_DESCRIPTION)) == FALSE)
		return FALSE;

	cg_upnp_service_setuserdata(service, dmr);
	for (action=cg_upnp_service_getactions(service); action; action=cg_upnp_action_next(action))
		cg_upnp_action_setuserdata(action, dmr);

	return TRUE;
}
