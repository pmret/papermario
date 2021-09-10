.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

.section .rodata

glabel jtbl_802465E8_915C98
.word L802430C8_912778, L802430D8_912788, L802430F8_9127A8, L80243118_9127C8, L80243138_9127E8, L80243148_9127F8, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L80243160_912810, L80243180_912830, L802431A0_912850, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L802431C4_912874, L802431D4_912884, L802431EC_91289C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L80243204_9128B4, L80243224_9128D4, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024327C_91292C, L8024323C_9128EC, L8024324C_9128FC, L8024326C_91291C, 0

.section .text

glabel func_80242F54_912604
/* 912604 80242F54 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* 912608 80242F58 AFB3003C */  sw        $s3, 0x3c($sp)
/* 91260C 80242F5C 0080982D */  daddu     $s3, $a0, $zero
/* 912610 80242F60 AFBF0048 */  sw        $ra, 0x48($sp)
/* 912614 80242F64 AFB50044 */  sw        $s5, 0x44($sp)
/* 912618 80242F68 AFB40040 */  sw        $s4, 0x40($sp)
/* 91261C 80242F6C AFB20038 */  sw        $s2, 0x38($sp)
/* 912620 80242F70 AFB10034 */  sw        $s1, 0x34($sp)
/* 912624 80242F74 AFB00030 */  sw        $s0, 0x30($sp)
/* 912628 80242F78 8E720148 */  lw        $s2, 0x148($s3)
/* 91262C 80242F7C 86440008 */  lh        $a0, 8($s2)
/* 912630 80242F80 0C00EABB */  jal       get_npc_unsafe
/* 912634 80242F84 00A0882D */   daddu    $s1, $a1, $zero
/* 912638 80242F88 0260202D */  daddu     $a0, $s3, $zero
/* 91263C 80242F8C 8E70000C */  lw        $s0, 0xc($s3)
/* 912640 80242F90 0040A82D */  daddu     $s5, $v0, $zero
/* 912644 80242F94 8E050000 */  lw        $a1, ($s0)
/* 912648 80242F98 0C0B1EAF */  jal       evt_get_variable
/* 91264C 80242F9C 26100004 */   addiu    $s0, $s0, 4
/* 912650 80242FA0 0260202D */  daddu     $a0, $s3, $zero
/* 912654 80242FA4 8E050000 */  lw        $a1, ($s0)
/* 912658 80242FA8 0C0B1EAF */  jal       evt_get_variable
/* 91265C 80242FAC 0040A02D */   daddu    $s4, $v0, $zero
/* 912660 80242FB0 AE420094 */  sw        $v0, 0x94($s2)
/* 912664 80242FB4 AFA00010 */  sw        $zero, 0x10($sp)
/* 912668 80242FB8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91266C 80242FBC 8C420030 */  lw        $v0, 0x30($v0)
/* 912670 80242FC0 AFA20014 */  sw        $v0, 0x14($sp)
/* 912674 80242FC4 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 912678 80242FC8 8C42001C */  lw        $v0, 0x1c($v0)
/* 91267C 80242FCC AFA20018 */  sw        $v0, 0x18($sp)
/* 912680 80242FD0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 912684 80242FD4 8C420024 */  lw        $v0, 0x24($v0)
/* 912688 80242FD8 AFA2001C */  sw        $v0, 0x1c($sp)
/* 91268C 80242FDC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 912690 80242FE0 8C420028 */  lw        $v0, 0x28($v0)
/* 912694 80242FE4 AFA20020 */  sw        $v0, 0x20($sp)
/* 912698 80242FE8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 91269C 80242FEC 3C014220 */  lui       $at, 0x4220
/* 9126A0 80242FF0 44810000 */  mtc1      $at, $f0
/* 9126A4 80242FF4 8C42002C */  lw        $v0, 0x2c($v0)
/* 9126A8 80242FF8 27B00010 */  addiu     $s0, $sp, 0x10
/* 9126AC 80242FFC E7A00028 */  swc1      $f0, 0x28($sp)
/* 9126B0 80243000 A7A0002C */  sh        $zero, 0x2c($sp)
/* 9126B4 80243004 12200012 */  beqz      $s1, .L80243050
/* 9126B8 80243008 AFA20024 */   sw       $v0, 0x24($sp)
/* 9126BC 8024300C AE600070 */  sw        $zero, 0x70($s3)
/* 9126C0 80243010 8EA30000 */  lw        $v1, ($s5)
/* 9126C4 80243014 2402F7FF */  addiu     $v0, $zero, -0x801
/* 9126C8 80243018 A6A0008E */  sh        $zero, 0x8e($s5)
/* 9126CC 8024301C 00621824 */  and       $v1, $v1, $v0
/* 9126D0 80243020 AEA30000 */  sw        $v1, ($s5)
/* 9126D4 80243024 8E4200D0 */  lw        $v0, 0xd0($s2)
/* 9126D8 80243028 8C420034 */  lw        $v0, 0x34($v0)
/* 9126DC 8024302C 54400005 */  bnel      $v0, $zero, .L80243044
/* 9126E0 80243030 2402FDFF */   addiu    $v0, $zero, -0x201
/* 9126E4 80243034 34620200 */  ori       $v0, $v1, 0x200
/* 9126E8 80243038 2403FFF7 */  addiu     $v1, $zero, -9
/* 9126EC 8024303C 08090C13 */  j         .L8024304C
/* 9126F0 80243040 00431024 */   and      $v0, $v0, $v1
.L80243044:
/* 9126F4 80243044 00621024 */  and       $v0, $v1, $v0
/* 9126F8 80243048 34420008 */  ori       $v0, $v0, 8
.L8024304C:
/* 9126FC 8024304C AEA20000 */  sw        $v0, ($s5)
.L80243050:
/* 912700 80243050 8E4300B0 */  lw        $v1, 0xb0($s2)
/* 912704 80243054 30620004 */  andi      $v0, $v1, 4
/* 912708 80243058 10400007 */  beqz      $v0, .L80243078
/* 91270C 8024305C 00000000 */   nop
/* 912710 80243060 824200B4 */  lb        $v0, 0xb4($s2)
/* 912714 80243064 14400086 */  bnez      $v0, .L80243280
/* 912718 80243068 0000102D */   daddu    $v0, $zero, $zero
/* 91271C 8024306C 2402FFFB */  addiu     $v0, $zero, -5
/* 912720 80243070 00621024 */  and       $v0, $v1, $v0
/* 912724 80243074 AE4200B0 */  sw        $v0, 0xb0($s2)
.L80243078:
/* 912728 80243078 8E620070 */  lw        $v0, 0x70($s3)
/* 91272C 8024307C 2442FFF4 */  addiu     $v0, $v0, -0xc
/* 912730 80243080 2C420003 */  sltiu     $v0, $v0, 3
/* 912734 80243084 10400007 */  beqz      $v0, .L802430A4
/* 912738 80243088 0260202D */   daddu    $a0, $s3, $zero
/* 91273C 8024308C 0280282D */  daddu     $a1, $s4, $zero
/* 912740 80243090 0C0908B1 */  jal       func_802422C4_911974
/* 912744 80243094 0200302D */   daddu    $a2, $s0, $zero
/* 912748 80243098 10400002 */  beqz      $v0, .L802430A4
/* 91274C 8024309C 24020014 */   addiu    $v0, $zero, 0x14
/* 912750 802430A0 AE620070 */  sw        $v0, 0x70($s3)
.L802430A4:
/* 912754 802430A4 8E630070 */  lw        $v1, 0x70($s3)
/* 912758 802430A8 2C620035 */  sltiu     $v0, $v1, 0x35
/* 91275C 802430AC 10400073 */  beqz      $v0, L8024327C_91292C
/* 912760 802430B0 00031080 */   sll      $v0, $v1, 2
/* 912764 802430B4 3C018024 */  lui       $at, %hi(jtbl_802465E8_915C98)
/* 912768 802430B8 00220821 */  addu      $at, $at, $v0
/* 91276C 802430BC 8C2265E8 */  lw        $v0, %lo(jtbl_802465E8_915C98)($at)
/* 912770 802430C0 00400008 */  jr        $v0
/* 912774 802430C4 00000000 */   nop
glabel L802430C8_912778
/* 912778 802430C8 0260202D */  daddu     $a0, $s3, $zero
/* 91277C 802430CC 0280282D */  daddu     $a1, $s4, $zero
/* 912780 802430D0 0C090909 */  jal       iwa_01_UnkNpcAIFunc18
/* 912784 802430D4 0200302D */   daddu    $a2, $s0, $zero
glabel L802430D8_912788
/* 912788 802430D8 0260202D */  daddu     $a0, $s3, $zero
/* 91278C 802430DC 0280282D */  daddu     $a1, $s4, $zero
/* 912790 802430E0 0C090926 */  jal       func_80242498_911B48
/* 912794 802430E4 0200302D */   daddu    $a2, $s0, $zero
/* 912798 802430E8 8E630070 */  lw        $v1, 0x70($s3)
/* 91279C 802430EC 24020002 */  addiu     $v0, $zero, 2
/* 9127A0 802430F0 14620063 */  bne       $v1, $v0, .L80243280
/* 9127A4 802430F4 0000102D */   daddu    $v0, $zero, $zero
glabel L802430F8_9127A8
/* 9127A8 802430F8 0260202D */  daddu     $a0, $s3, $zero
/* 9127AC 802430FC 0280282D */  daddu     $a1, $s4, $zero
/* 9127B0 80243100 0C090972 */  jal       iwa_01_UnkNpcAIFunc21
/* 9127B4 80243104 0200302D */   daddu    $a2, $s0, $zero
/* 9127B8 80243108 8E630070 */  lw        $v1, 0x70($s3)
/* 9127BC 8024310C 24020003 */  addiu     $v0, $zero, 3
/* 9127C0 80243110 1462005B */  bne       $v1, $v0, .L80243280
/* 9127C4 80243114 0000102D */   daddu    $v0, $zero, $zero
glabel L80243118_9127C8
/* 9127C8 80243118 0260202D */  daddu     $a0, $s3, $zero
/* 9127CC 8024311C 0280282D */  daddu     $a1, $s4, $zero
/* 9127D0 80243120 0C090999 */  jal       iwa_01_UnkNpcAIFunc20
/* 9127D4 80243124 0200302D */   daddu    $a2, $s0, $zero
/* 9127D8 80243128 8E630070 */  lw        $v1, 0x70($s3)
/* 9127DC 8024312C 24020004 */  addiu     $v0, $zero, 4
/* 9127E0 80243130 14620053 */  bne       $v1, $v0, .L80243280
/* 9127E4 80243134 0000102D */   daddu    $v0, $zero, $zero
glabel L80243138_9127E8
/* 9127E8 80243138 0260202D */  daddu     $a0, $s3, $zero
/* 9127EC 8024313C 0280282D */  daddu     $a1, $s4, $zero
/* 9127F0 80243140 0C0909BB */  jal       iwa_01_UnkNpcAIFunc22
/* 9127F4 80243144 0200302D */   daddu    $a2, $s0, $zero
glabel L80243148_9127F8
/* 9127F8 80243148 0260202D */  daddu     $a0, $s3, $zero
/* 9127FC 8024314C 0280282D */  daddu     $a1, $s4, $zero
/* 912800 80243150 0C0909E5 */  jal       iwa_01_UnkFunc8
/* 912804 80243154 0200302D */   daddu    $a2, $s0, $zero
/* 912808 80243158 08090CA0 */  j         .L80243280
/* 91280C 8024315C 0000102D */   daddu    $v0, $zero, $zero
glabel L80243160_912810
/* 912810 80243160 0260202D */  daddu     $a0, $s3, $zero
/* 912814 80243164 0280282D */  daddu     $a1, $s4, $zero
/* 912818 80243168 0C0127DF */  jal       func_80049F7C
/* 91281C 8024316C 0200302D */   daddu    $a2, $s0, $zero
/* 912820 80243170 8E630070 */  lw        $v1, 0x70($s3)
/* 912824 80243174 2402000D */  addiu     $v0, $zero, 0xd
/* 912828 80243178 14620041 */  bne       $v1, $v0, .L80243280
/* 91282C 8024317C 0000102D */   daddu    $v0, $zero, $zero
glabel L80243180_912830
/* 912830 80243180 0260202D */  daddu     $a0, $s3, $zero
/* 912834 80243184 0280282D */  daddu     $a1, $s4, $zero
/* 912838 80243188 0C012849 */  jal       func_8004A124
/* 91283C 8024318C 0200302D */   daddu    $a2, $s0, $zero
/* 912840 80243190 8E630070 */  lw        $v1, 0x70($s3)
/* 912844 80243194 2402000E */  addiu     $v0, $zero, 0xe
/* 912848 80243198 14620039 */  bne       $v1, $v0, .L80243280
/* 91284C 8024319C 0000102D */   daddu    $v0, $zero, $zero
glabel L802431A0_912850
/* 912850 802431A0 96A2008E */  lhu       $v0, 0x8e($s5)
/* 912854 802431A4 2442FFFF */  addiu     $v0, $v0, -1
/* 912858 802431A8 A6A2008E */  sh        $v0, 0x8e($s5)
/* 91285C 802431AC 00021400 */  sll       $v0, $v0, 0x10
/* 912860 802431B0 14400033 */  bnez      $v0, .L80243280
/* 912864 802431B4 0000102D */   daddu    $v0, $zero, $zero
/* 912868 802431B8 24020028 */  addiu     $v0, $zero, 0x28
/* 91286C 802431BC 08090C9F */  j         L8024327C_91292C
/* 912870 802431C0 AE620070 */   sw       $v0, 0x70($s3)
glabel L802431C4_912874
/* 912874 802431C4 0260202D */  daddu     $a0, $s3, $zero
/* 912878 802431C8 0280282D */  daddu     $a1, $s4, $zero
/* 91287C 802431CC 0C090A42 */  jal       iwa_01_UnkNpcAIFunc16
/* 912880 802431D0 0200302D */   daddu    $a2, $s0, $zero
glabel L802431D4_912884
/* 912884 802431D4 0260202D */  daddu     $a0, $s3, $zero
/* 912888 802431D8 0280282D */  daddu     $a1, $s4, $zero
/* 91288C 802431DC 0C090A56 */  jal       func_80242958_912008
/* 912890 802431E0 0200302D */   daddu    $a2, $s0, $zero
/* 912894 802431E4 08090CA0 */  j         .L80243280
/* 912898 802431E8 0000102D */   daddu    $v0, $zero, $zero
glabel L802431EC_91289C
/* 91289C 802431EC 0260202D */  daddu     $a0, $s3, $zero
/* 9128A0 802431F0 0280282D */  daddu     $a1, $s4, $zero
/* 9128A4 802431F4 0C090ABE */  jal       iwa_01_UnkFunc10
/* 9128A8 802431F8 0200302D */   daddu    $a2, $s0, $zero
/* 9128AC 802431FC 08090CA0 */  j         .L80243280
/* 9128B0 80243200 0000102D */   daddu    $v0, $zero, $zero
glabel L80243204_9128B4
/* 9128B4 80243204 0260202D */  daddu     $a0, $s3, $zero
/* 9128B8 80243208 0280282D */  daddu     $a1, $s4, $zero
/* 9128BC 8024320C 0C090B12 */  jal       func_80242C48_9122F8
/* 9128C0 80243210 0200302D */   daddu    $a2, $s0, $zero
/* 9128C4 80243214 8E630070 */  lw        $v1, 0x70($s3)
/* 9128C8 80243218 24020029 */  addiu     $v0, $zero, 0x29
/* 9128CC 8024321C 14620018 */  bne       $v1, $v0, .L80243280
/* 9128D0 80243220 0000102D */   daddu    $v0, $zero, $zero
glabel L80243224_9128D4
/* 9128D4 80243224 0260202D */  daddu     $a0, $s3, $zero
/* 9128D8 80243228 0280282D */  daddu     $a1, $s4, $zero
/* 9128DC 8024322C 0C090B3D */  jal       iwa_01_UnkFunc9
/* 9128E0 80243230 0200302D */   daddu    $a2, $s0, $zero
/* 9128E4 80243234 08090CA0 */  j         .L80243280
/* 9128E8 80243238 0000102D */   daddu    $v0, $zero, $zero
glabel L8024323C_9128EC
/* 9128EC 8024323C 0260202D */  daddu     $a0, $s3, $zero
/* 9128F0 80243240 0280282D */  daddu     $a1, $s4, $zero
/* 9128F4 80243244 0C090B8B */  jal       iwa_01_UnkNpcAIFunc19
/* 9128F8 80243248 0200302D */   daddu    $a2, $s0, $zero
glabel L8024324C_9128FC
/* 9128FC 8024324C 0260202D */  daddu     $a0, $s3, $zero
/* 912900 80243250 0280282D */  daddu     $a1, $s4, $zero
/* 912904 80243254 0C090BAA */  jal       iwa_01_UnkNpcAIFunc17
/* 912908 80243258 0200302D */   daddu    $a2, $s0, $zero
/* 91290C 8024325C 8E630070 */  lw        $v1, 0x70($s3)
/* 912910 80243260 24020034 */  addiu     $v0, $zero, 0x34
/* 912914 80243264 14620006 */  bne       $v1, $v0, .L80243280
/* 912918 80243268 0000102D */   daddu    $v0, $zero, $zero
glabel L8024326C_91291C
/* 91291C 8024326C 0260202D */  daddu     $a0, $s3, $zero
/* 912920 80243270 0280282D */  daddu     $a1, $s4, $zero
/* 912924 80243274 0C090BC4 */  jal       dup_iwa_01_UnkDurationCheck
/* 912928 80243278 0200302D */   daddu    $a2, $s0, $zero
glabel L8024327C_91292C
/* 91292C 8024327C 0000102D */  daddu     $v0, $zero, $zero
.L80243280:
/* 912930 80243280 8FBF0048 */  lw        $ra, 0x48($sp)
/* 912934 80243284 8FB50044 */  lw        $s5, 0x44($sp)
/* 912938 80243288 8FB40040 */  lw        $s4, 0x40($sp)
/* 91293C 8024328C 8FB3003C */  lw        $s3, 0x3c($sp)
/* 912940 80243290 8FB20038 */  lw        $s2, 0x38($sp)
/* 912944 80243294 8FB10034 */  lw        $s1, 0x34($sp)
/* 912948 80243298 8FB00030 */  lw        $s0, 0x30($sp)
/* 91294C 8024329C 03E00008 */  jr        $ra
/* 912950 802432A0 27BD0050 */   addiu    $sp, $sp, 0x50
/* 912954 802432A4 00000000 */  nop
/* 912958 802432A8 00000000 */  nop
/* 91295C 802432AC 00000000 */  nop
