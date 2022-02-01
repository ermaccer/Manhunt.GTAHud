#pragma once
#include "Entity.h"
#include "Ped.h"
#include "Hunter.h"

enum ePlayerFlags {
	PLF_CARRYING_BODY = 0x200000,
};

class CPlayer: public CAutoPed {
public:
	char field_678;
	char field_679;
	char field_67A;
	char field_67B;
	char field_67C;
	char field_67D;
	char field_67E;
	char field_67F;
	char field_680;
	char field_681;
	char field_682;
	char field_683;
	char field_684;
	char field_685;
	char field_686;
	char field_687;
	char field_688;
	char field_689;
	char field_68A;
	char field_68B;
	char field_68C;
	char field_68D;
	char field_68E;
	char field_68F;
	char field_690;
	char field_691;
	char field_692;
	char field_693;
	char field_694;
	char field_695;
	char field_696;
	char field_697;
	char field_698;
	char field_699;
	char field_69A;
	char field_69B;
	char field_69C;
	char field_69D;
	char field_69E;
	char field_69F;
	char field_6A0;
	char field_6A1;
	char field_6A2;
	char field_6A3;
	char field_6A4;
	char field_6A5;
	char field_6A6;
	char field_6A7;
	char field_6A8;
	char field_6A9;
	char field_6AA;
	char field_6AB;
	char field_6AC;
	char field_6AD;
	char field_6AE;
	char field_6AF;
	char field_6B0;
	char field_6B1;
	char field_6B2;
	char field_6B3;
	char field_6B4;
	char field_6B5;
	char field_6B6;
	char field_6B7;
	char field_6B8;
	char field_6B9;
	char field_6BA;
	char field_6BB;
	char field_6BC;
	char field_6BD;
	char field_6BE;
	char field_6BF;
	char field_6C0;
	char field_6C1;
	char field_6C2;
	char field_6C3;
	char field_6C4;
	char field_6C5;
	char field_6C6;
	char field_6C7;
	char field_6C8;
	char field_6C9;
	char field_6CA;
	char field_6CB;
	char field_6CC;
	char field_6CD;
	char field_6CE;
	char field_6CF;
	char field_6D0;
	char field_6D1;
	char field_6D2;
	char field_6D3;
	char field_6D4;
	char field_6D5;
	char field_6D6;
	char field_6D7;
	char field_6D8;
	char field_6D9;
	char field_6DA;
	char field_6DB;
	int field_6DC;
	int field_6E0;
	int field_6E4;
	char field_6E8;
	char field_6E9;
	char field_6EA;
	char field_6EB;
	char field_6EC;
	char field_6ED;
	char field_6EE;
	char field_6EF;
	char field_6F0;
	char field_6F1;
	char field_6F2;
	char field_6F3;
	char field_6F4;
	char field_6F5;
	char field_6F6;
	char field_6F7;
	char field_6F8;
	char field_6F9;
	char field_6FA;
	char field_6FB;
	char field_6FC;
	char field_6FD;
	char field_6FE;
	char field_6FF;
	char field_700;
	char field_701;
	char field_702;
	char field_703;
	char field_704;
	char field_705;
	char field_706;
	char field_707;
	char field_708;
	char field_709;
	char field_70A;
	char field_70B;
	char field_70C;
	char field_70D;
	char field_70E;
	char field_70F;
	char field_710;
	char field_711;
	char field_712;
	char field_713;
	char field_714;
	char field_715;
	char field_716;
	char field_717;
	char field_718;
	char field_719;
	char field_71A;
	char field_71B;
	char field_71C;
	char field_71D;
	char field_71E;
	char field_71F;
	char field_720;
	char field_721;
	char field_722;
	char field_723;
	char field_724;
	char field_725;
	char field_726;
	char field_727;
	char field_728;
	char field_729;
	char field_72A;
	char field_72B;
	char field_72C;
	char field_72D;
	char field_72E;
	char field_72F;
	char field_730;
	char field_731;
	char field_732;
	char field_733;
	char field_734;
	char field_735;
	char field_736;
	char field_737;
	char field_738;
	char field_739;
	char field_73A;
	char field_73B;
	char field_73C;
	char field_73D;
	char field_73E;
	char field_73F;
	char field_740;
	char field_741;
	char field_742;
	char field_743;
	char field_744;
	char field_745;
	char field_746;
	char field_747;
	char field_748;
	char field_749;
	char field_74A;
	char field_74B;
	char field_74C;
	char field_74D;
	char field_74E;
	char field_74F;
	char field_750;
	char field_751;
	char field_752;
	char field_753;
	char field_754;
	char field_755;
	char field_756;
	char field_757;
	char field_758;
	char field_759;
	char field_75A;
	char field_75B;
	char field_75C;
	char field_75D;
	char field_75E;
	char field_75F;
	int field_760;
	char field_764;
	char field_765;
	char field_766;
	char field_767;
	char field_768;
	char field_769;
	char field_76A;
	char field_76B;
	char field_76C;
	char field_76D;
	char field_76E;
	char field_76F;
	char field_770;
	char field_771;
	char field_772;
	char field_773;
	char field_774;
	char field_775;
	char field_776;
	char field_777;
	char field_778;
	char field_779;
	char field_77A;
	char field_77B;
	char field_77C;
	char field_77D;
	char field_77E;
	char field_77F;
	char field_780;
	char field_781;
	char field_782;
	char field_783;
	char field_784;
	char field_785;
	char field_786;
	char field_787;
	char field_788;
	char field_789;
	char field_78A;
	char field_78B;
	char field_78C;
	char field_78D;
	char field_78E;
	char field_78F;
	char field_790;
	char field_791;
	char field_792;
	char field_793;
	char field_794;
	char field_795;
	char field_796;
	char field_797;
	char field_798;
	char field_799;
	char field_79A;
	char field_79B;
	char field_79C;
	char field_79D;
	char field_79E;
	char field_79F;
	char field_7A0;
	char field_7A1;
	char field_7A2;
	char field_7A3;
	char field_7A4;
	char field_7A5;
	char field_7A6;
	char field_7A7;
	float field_7A8;
	float field_7AC;
	char field_7B0;
	char field_7B1;
	char field_7B2;
	char field_7B3;
	int field_7B4;
	char field_7B8;
	char field_7B9;
	char field_7BA;
	char field_7BB;
	float field_7BC;
	char field_7C0;
	char field_7C1;
	char field_7C2;
	char field_7C3;
	char field_7C4;
	char field_7C5;
	char field_7C6;
	char field_7C7;
	char field_7C8;
	char field_7C9;
	char field_7CA;
	char field_7CB;
	char field_7CC;
	char field_7CD;
	char field_7CE;
	char field_7CF;
	int field_7D0;
	float field_7D4;
	float field_7D8;
	int field_7DC;
	float field_7E0;
	float field_7E4;
	char m_bCameraLookAround;
	char field_7E9;
	char field_7EA;
	char field_7EB;
	char field_7EC;
	char field_7ED;
	char field_7EE;
	char field_7EF;
	char field_7F0;
	char field_7F1;
	char field_7F2;
	char field_7F3;
	char m_bIsPlayerTranqed;
	char field_7F5;
	char field_7F6;
	char field_7F7;
	char field_7F8;
	char field_7F9;
	char field_7FA;
	char field_7FB;
	char field_7FC;
	char field_7FD;
	char field_7FE;
	char field_7FF;
	char field_800;
	char field_801;
	char field_802;
	char field_803;
	char field_804;
	char field_805;
	char field_806;
	char field_807;
	char field_808;
	char field_809;
	char field_80A;
	char field_80B;
	char field_80C;
	char field_80D;
	char field_80E;
	char field_80F;
	char field_810;
	char field_811;
	char field_812;
	char field_813;
	char field_814;
	char field_815;
	char field_816;
	char field_817;
	char field_818;
	char field_819;
	char field_81A;
	char field_81B;
	char field_81C;
	char field_81D;
	char field_81E;
	char field_81F;
	char field_820;
	char field_821;
	char field_822;
	char field_823;
	char field_824;
	char field_825;
	char field_826;
	char field_827;
	char field_828;
	char field_829;
	char field_82A;
	char field_82B;
	char field_82C;
	char field_82D;
	char field_82E;
	char field_82F;
	char field_830;
	char field_831;
	char field_832;
	char field_833;
	char field_834;
	char field_835;
	char field_836;
	char field_837;
	int field_838;
	int m_nAccumulatedTime;
	char field_840;
	char field_841;
	char field_842;
	char field_843;
	int m_nPlayerFlags;
	char field_848;
	char field_849;
	char field_84A;
	char field_84B;
	float m_fStamina;
	int field_850;
	int m_pCameraPointer;
	char field_858;
	char field_859;
	char field_85A;
	char field_85B;
	char field_85C;
	char field_85D;
	char field_85E;
	char field_85F;
	char field_860;
	char field_861;
	char field_862;
	char field_863;
	float field_864;
	char field_868;
	char field_869;
	char field_86A;
	char field_86B;
	char field_86C;
	char field_86D;
	char field_86E;
	char field_86F;
	char field_870;
	char field_871;
	char field_872;
	char field_873;
	int field_874;
	float field_878;
	int field_87C;
	char field_880;
	char field_881;
	char field_882;
	char field_883;
	char field_884;
	char field_885;
	char field_886;
	char field_887;
	char field_888;
	char field_889;
	char field_88A;
	char field_88B;
	char field_88C;
	char field_88D;
	char field_88E;
	char field_88F;
	char field_890;
	char field_891;
	char field_892;
	char field_893;
	char field_894;
	char field_895;
	char field_896;
	char field_897;
	char field_898;
	char field_899;
	char field_89A;
	char field_89B;
	CCollectable *m_pCurrentCollectable;
	char field_8A0;
	char field_8A1;
	char field_8A2;
	char field_8A3;
	char field_8A4;
	char field_8A5;
	char field_8A6;
	char field_8A7;
	char field_8A8;
	char field_8A9;
	char field_8AA;
	char field_8AB;
	char field_8AC;
	char field_8AD;
	char field_8AE;
	char field_8AF;
	CEntity *m_pDeadBody;
	CHunter *m_pExecuteHunter;
	char field_8B8;
	char field_8B9;
	char field_8BA;
	char field_8BB;
	char field_8BC;
	char field_8BD;
	char field_8BE;
	char field_8BF;
	char field_8C0;
	char field_8C1;
	char field_8C2;
	char field_8C3;
	float field_8C4;
	char field_8C8;
	char field_8C9;
	char field_8CA;
	char field_8CB;
	int field_8CC;
	int field_8D0;
	char field_8D4;
	char field_8D5;
	char field_8D6;
	char field_8D7;
	int field_8D8;
	int field_8DC;
	int field_8E0;
	CVector field_8E4;
	char field_8F0;
	char field_8F1;
	char field_8F2;
	char field_8F3;
	int field_8F4;
	char field_8F8;
	char field_8F9;
	char field_8FA;
	char field_8FB;
	char field_8FC;
	char field_8FD;
	char field_8FE;
	char field_8FF;
	char field_900;
	char field_901;
	char field_902;
	char field_903;
	char field_904;
	char field_905;
	char field_906;
	char field_907;
	char field_908;
	char field_909;
	char field_90A;
	char field_90B;
	char field_90C;
	char field_90D;
	char field_90E;
	char field_90F;
	char field_910;
	char field_911;
	char field_912;
	char field_913;
	char field_914;
	char field_915;
	char field_916;
	char field_917;
	char field_918;
	char field_919;
	char field_91A;
	char field_91B;
	float field_91C;
	char field_920;
	char field_921;
	char field_922;
	char field_923;
	char field_924;
	char field_925;
	char field_926;
	char field_927;
	char field_928;
	char field_929;
	char field_92A;
	char field_92B;
	char field_92C;
	char field_92D;
	char field_92E;
	char field_92F;
	char field_930;
	char field_931;
	char field_932;
	char field_933;
	char field_934;
	char field_935;
	char field_936;
	char field_937;
	char field_938;
	char field_939;
	char field_93A;
	char field_93B;
	char field_93C;
	char field_93D;
	char field_93E;
	char field_93F;
	float field_940;
	char field_944;
	char field_945;
	char field_946;
	char field_947;
	int field_948;
	char field_94C;
	char field_94D;
	char field_94E;
	char field_94F;
	char field_950;
	char field_951;
	char field_952;
	char field_953;
	char field_954;
	char field_955;
	char field_956;
	char field_957;
	int field_958;
	char field_95C;
	char field_95D;
	char field_95E;
	char field_95F;
	char field_960;
	char field_961;
	char field_962;
	char field_963;
	char field_964;
	char field_965;
	char field_966;
	char field_967;
	char field_968;
	char field_969;
	char field_96A;
	char field_96B;
	float m_fExecuteTime;
	char field_970;
	char field_971;
	char field_972;
	char field_973;
	float field_974;
	char field_978;
	char field_979;
	char field_97A;
	char field_97B;
	char field_97C;
	char field_97D;
	char field_97E;
	char field_97F;
	char field_980;
	char field_981;
	char field_982;
	char field_983;
	char field_984;
	char field_985;
	char field_986;
	char field_987;
	char field_988;
	char field_989;
	char field_98A;
	char field_98B;
	char field_98C;
	char field_98D;
	char field_98E;
	char field_98F;
	char field_990;
	char field_991;
	char field_992;
	char field_993;
	char field_994;
	char field_995;
	char field_996;
	char field_997;
	char field_998;
	char field_999;
	char field_99A;
	char field_99B;
	char field_99C;
	char field_99D;
	char field_99E;
	char field_99F;
	char field_9A0;
	char field_9A1;
	char field_9A2;
	char field_9A3;
	char field_9A4;
	char field_9A5;
	char field_9A6;
	char field_9A7;
	char field_9A8;
	char field_9A9;
	char field_9AA;
	char field_9AB;
	char field_9AC;
	char field_9AD;
	char field_9AE;
	char field_9AF;
	char field_9B0;
	char field_9B1;
	char field_9B2;
	char field_9B3;
	char field_9B4;
	char field_9B5;
	char field_9B6;
	char field_9B7;
	char field_9B8;
	char field_9B9;
	char field_9BA;
	char field_9BB;
	char field_9BC;
	char field_9BD;
	char field_9BE;
	char field_9BF;
	char field_9C0;
	char field_9C1;
	char field_9C2;
	char field_9C3;
	char field_9C4;
	char field_9C5;
	char field_9C6;
	char field_9C7;
	char field_9C8;
	char field_9C9;
	char field_9CA;
	char field_9CB;
	char field_9CC;
	char field_9CD;
	char field_9CE;
	char field_9CF;
	char field_9D0;
	char field_9D1;
	char field_9D2;
	char field_9D3;
	char field_9D4;
	char field_9D5;
	char field_9D6;
	char field_9D7;
	char field_9D8;
	char field_9D9;
	char field_9DA;
	char field_9DB;
	char field_9DC;
	char field_9DD;
	char field_9DE;
	char field_9DF;
	char field_9E0;
	char field_9E1;
	char field_9E2;
	char field_9E3;
	char field_9E4;
	char field_9E5;
	char field_9E6;
	char field_9E7;
	char field_9E8;
	char field_9E9;
	char field_9EA;
	char field_9EB;
	char field_9EC;
	char field_9ED;
	char field_9EE;
	char field_9EF;
	char field_9F0;
	char field_9F1;
	char field_9F2;
	char field_9F3;
	char field_9F4;
	char field_9F5;
	char field_9F6;
	char field_9F7;
	char field_9F8;
	char field_9F9;
	char field_9FA;
	char field_9FB;
	char field_9FC;
	char field_9FD;
	char field_9FE;
	char field_9FF;
	char field_A00;
	char field_A01;
	char field_A02;
	char field_A03;
	char field_A04;
	char field_A05;
	char field_A06;
	char field_A07;
	char field_A08;
	char field_A09;
	char field_A0A;
	char field_A0B;
	char field_A0C;
	char field_A0D;
	char field_A0E;
	char field_A0F;
	char field_A10;
	char field_A11;
	char field_A12;
	char field_A13;
	char field_A14;
	char field_A15;
	char field_A16;
	char field_A17;
	char field_A18;
	char field_A19;
	char field_A1A;
	char field_A1B;
	char field_A1C;
	char field_A1D;
	char field_A1E;
	char field_A1F;

	void StartLookAround();
	void ForcePlayAnim(const char* name);
	void ForcePlayFullBodyAnim(const char* name);
	void AccumulateTime();


	int GetExecuteStage();

};