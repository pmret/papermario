.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243018_BE67C8
/* BE67C8 80243018 27BDFFB0 */  addiu     $sp, $sp, -0x50
/* BE67CC 8024301C AFB3003C */  sw        $s3, 0x3c($sp)
/* BE67D0 80243020 0080982D */  daddu     $s3, $a0, $zero
/* BE67D4 80243024 AFBF0048 */  sw        $ra, 0x48($sp)
/* BE67D8 80243028 AFB50044 */  sw        $s5, 0x44($sp)
/* BE67DC 8024302C AFB40040 */  sw        $s4, 0x40($sp)
/* BE67E0 80243030 AFB20038 */  sw        $s2, 0x38($sp)
/* BE67E4 80243034 AFB10034 */  sw        $s1, 0x34($sp)
/* BE67E8 80243038 AFB00030 */  sw        $s0, 0x30($sp)
/* BE67EC 8024303C 8E720148 */  lw        $s2, 0x148($s3)
/* BE67F0 80243040 86440008 */  lh        $a0, 8($s2)
/* BE67F4 80243044 0C00EABB */  jal       get_npc_unsafe
/* BE67F8 80243048 00A0882D */   daddu    $s1, $a1, $zero
/* BE67FC 8024304C 0260202D */  daddu     $a0, $s3, $zero
/* BE6800 80243050 8E70000C */  lw        $s0, 0xc($s3)
/* BE6804 80243054 0040A82D */  daddu     $s5, $v0, $zero
/* BE6808 80243058 8E050000 */  lw        $a1, ($s0)
/* BE680C 8024305C 0C0B1EAF */  jal       get_variable
/* BE6810 80243060 26100004 */   addiu    $s0, $s0, 4
/* BE6814 80243064 0260202D */  daddu     $a0, $s3, $zero
/* BE6818 80243068 8E050000 */  lw        $a1, ($s0)
/* BE681C 8024306C 0C0B1EAF */  jal       get_variable
/* BE6820 80243070 0040A02D */   daddu    $s4, $v0, $zero
/* BE6824 80243074 AE420094 */  sw        $v0, 0x94($s2)
/* BE6828 80243078 AFA00010 */  sw        $zero, 0x10($sp)
/* BE682C 8024307C 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE6830 80243080 8C420030 */  lw        $v0, 0x30($v0)
/* BE6834 80243084 AFA20014 */  sw        $v0, 0x14($sp)
/* BE6838 80243088 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE683C 8024308C 8C42001C */  lw        $v0, 0x1c($v0)
/* BE6840 80243090 AFA20018 */  sw        $v0, 0x18($sp)
/* BE6844 80243094 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE6848 80243098 8C420024 */  lw        $v0, 0x24($v0)
/* BE684C 8024309C AFA2001C */  sw        $v0, 0x1c($sp)
/* BE6850 802430A0 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE6854 802430A4 8C420028 */  lw        $v0, 0x28($v0)
/* BE6858 802430A8 AFA20020 */  sw        $v0, 0x20($sp)
/* BE685C 802430AC 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE6860 802430B0 3C014220 */  lui       $at, 0x4220
/* BE6864 802430B4 44810000 */  mtc1      $at, $f0
/* BE6868 802430B8 8C42002C */  lw        $v0, 0x2c($v0)
/* BE686C 802430BC 27B00010 */  addiu     $s0, $sp, 0x10
/* BE6870 802430C0 E7A00028 */  swc1      $f0, 0x28($sp)
/* BE6874 802430C4 A7A0002C */  sh        $zero, 0x2c($sp)
/* BE6878 802430C8 12200012 */  beqz      $s1, .L80243114
/* BE687C 802430CC AFA20024 */   sw       $v0, 0x24($sp)
/* BE6880 802430D0 AE600070 */  sw        $zero, 0x70($s3)
/* BE6884 802430D4 8EA30000 */  lw        $v1, ($s5)
/* BE6888 802430D8 2402F7FF */  addiu     $v0, $zero, -0x801
/* BE688C 802430DC A6A0008E */  sh        $zero, 0x8e($s5)
/* BE6890 802430E0 00621824 */  and       $v1, $v1, $v0
/* BE6894 802430E4 AEA30000 */  sw        $v1, ($s5)
/* BE6898 802430E8 8E4200D0 */  lw        $v0, 0xd0($s2)
/* BE689C 802430EC 8C420034 */  lw        $v0, 0x34($v0)
/* BE68A0 802430F0 54400005 */  bnel      $v0, $zero, .L80243108
/* BE68A4 802430F4 2402FDFF */   addiu    $v0, $zero, -0x201
/* BE68A8 802430F8 34620200 */  ori       $v0, $v1, 0x200
/* BE68AC 802430FC 2403FFF7 */  addiu     $v1, $zero, -9
/* BE68B0 80243100 08090C44 */  j         .L80243110
/* BE68B4 80243104 00431024 */   and      $v0, $v0, $v1
.L80243108:
/* BE68B8 80243108 00621024 */  and       $v0, $v1, $v0
/* BE68BC 8024310C 34420008 */  ori       $v0, $v0, 8
.L80243110:
/* BE68C0 80243110 AEA20000 */  sw        $v0, ($s5)
.L80243114:
/* BE68C4 80243114 8E4300B0 */  lw        $v1, 0xb0($s2)
/* BE68C8 80243118 30620004 */  andi      $v0, $v1, 4
/* BE68CC 8024311C 10400007 */  beqz      $v0, .L8024313C
/* BE68D0 80243120 00000000 */   nop
/* BE68D4 80243124 824200B4 */  lb        $v0, 0xb4($s2)
/* BE68D8 80243128 14400086 */  bnez      $v0, .L80243344
/* BE68DC 8024312C 0000102D */   daddu    $v0, $zero, $zero
/* BE68E0 80243130 2402FFFB */  addiu     $v0, $zero, -5
/* BE68E4 80243134 00621024 */  and       $v0, $v1, $v0
/* BE68E8 80243138 AE4200B0 */  sw        $v0, 0xb0($s2)
.L8024313C:
/* BE68EC 8024313C 8E620070 */  lw        $v0, 0x70($s3)
/* BE68F0 80243140 2442FFF4 */  addiu     $v0, $v0, -0xc
/* BE68F4 80243144 2C420003 */  sltiu     $v0, $v0, 3
/* BE68F8 80243148 10400007 */  beqz      $v0, .L80243168
/* BE68FC 8024314C 0260202D */   daddu    $a0, $s3, $zero
/* BE6900 80243150 0280282D */  daddu     $a1, $s4, $zero
/* BE6904 80243154 0C0908E2 */  jal       func_80242388_BE5B38
/* BE6908 80243158 0200302D */   daddu    $a2, $s0, $zero
/* BE690C 8024315C 10400002 */  beqz      $v0, .L80243168
/* BE6910 80243160 24020014 */   addiu    $v0, $zero, 0x14
/* BE6914 80243164 AE620070 */  sw        $v0, 0x70($s3)
.L80243168:
/* BE6918 80243168 8E630070 */  lw        $v1, 0x70($s3)
/* BE691C 8024316C 2C620035 */  sltiu     $v0, $v1, 0x35
/* BE6920 80243170 10400073 */  beqz      $v0, L80243340_BE6AF0
/* BE6924 80243174 00031080 */   sll      $v0, $v1, 2
/* BE6928 80243178 3C018024 */  lui       $at, %hi(jtbl_80244350_BE7B00)
/* BE692C 8024317C 00220821 */  addu      $at, $at, $v0
/* BE6930 80243180 8C224350 */  lw        $v0, %lo(jtbl_80244350_BE7B00)($at)
/* BE6934 80243184 00400008 */  jr        $v0
/* BE6938 80243188 00000000 */   nop
glabel L8024318C_BE693C
/* BE693C 8024318C 0260202D */  daddu     $a0, $s3, $zero
/* BE6940 80243190 0280282D */  daddu     $a1, $s4, $zero
/* BE6944 80243194 0C09093A */  jal       arn_04_UnkNpcAIFunc18
/* BE6948 80243198 0200302D */   daddu    $a2, $s0, $zero
glabel L8024319C_BE694C
/* BE694C 8024319C 0260202D */  daddu     $a0, $s3, $zero
/* BE6950 802431A0 0280282D */  daddu     $a1, $s4, $zero
/* BE6954 802431A4 0C090957 */  jal       func_8024255C_BE5D0C
/* BE6958 802431A8 0200302D */   daddu    $a2, $s0, $zero
/* BE695C 802431AC 8E630070 */  lw        $v1, 0x70($s3)
/* BE6960 802431B0 24020002 */  addiu     $v0, $zero, 2
/* BE6964 802431B4 14620063 */  bne       $v1, $v0, .L80243344
/* BE6968 802431B8 0000102D */   daddu    $v0, $zero, $zero
glabel L802431BC_BE696C
/* BE696C 802431BC 0260202D */  daddu     $a0, $s3, $zero
/* BE6970 802431C0 0280282D */  daddu     $a1, $s4, $zero
/* BE6974 802431C4 0C0909A3 */  jal       arn_04_UnkNpcAIFunc21
/* BE6978 802431C8 0200302D */   daddu    $a2, $s0, $zero
/* BE697C 802431CC 8E630070 */  lw        $v1, 0x70($s3)
/* BE6980 802431D0 24020003 */  addiu     $v0, $zero, 3
/* BE6984 802431D4 1462005B */  bne       $v1, $v0, .L80243344
/* BE6988 802431D8 0000102D */   daddu    $v0, $zero, $zero
glabel L802431DC_BE698C
/* BE698C 802431DC 0260202D */  daddu     $a0, $s3, $zero
/* BE6990 802431E0 0280282D */  daddu     $a1, $s4, $zero
/* BE6994 802431E4 0C0909CA */  jal       arn_04_UnkNpcAIFunc20
/* BE6998 802431E8 0200302D */   daddu    $a2, $s0, $zero
/* BE699C 802431EC 8E630070 */  lw        $v1, 0x70($s3)
/* BE69A0 802431F0 24020004 */  addiu     $v0, $zero, 4
/* BE69A4 802431F4 14620053 */  bne       $v1, $v0, .L80243344
/* BE69A8 802431F8 0000102D */   daddu    $v0, $zero, $zero
glabel L802431FC_BE69AC
/* BE69AC 802431FC 0260202D */  daddu     $a0, $s3, $zero
/* BE69B0 80243200 0280282D */  daddu     $a1, $s4, $zero
/* BE69B4 80243204 0C0909EC */  jal       func_802427B0_BE5F60
/* BE69B8 80243208 0200302D */   daddu    $a2, $s0, $zero
glabel L8024320C_BE69BC
/* BE69BC 8024320C 0260202D */  daddu     $a0, $s3, $zero
/* BE69C0 80243210 0280282D */  daddu     $a1, $s4, $zero
/* BE69C4 80243214 0C090A16 */  jal       func_80242858_BE6008
/* BE69C8 80243218 0200302D */   daddu    $a2, $s0, $zero
/* BE69CC 8024321C 08090CD1 */  j         .L80243344
/* BE69D0 80243220 0000102D */   daddu    $v0, $zero, $zero
glabel L80243224_BE69D4
/* BE69D4 80243224 0260202D */  daddu     $a0, $s3, $zero
/* BE69D8 80243228 0280282D */  daddu     $a1, $s4, $zero
/* BE69DC 8024322C 0C0127DF */  jal       func_80049F7C
/* BE69E0 80243230 0200302D */   daddu    $a2, $s0, $zero
/* BE69E4 80243234 8E630070 */  lw        $v1, 0x70($s3)
/* BE69E8 80243238 2402000D */  addiu     $v0, $zero, 0xd
/* BE69EC 8024323C 14620041 */  bne       $v1, $v0, .L80243344
/* BE69F0 80243240 0000102D */   daddu    $v0, $zero, $zero
glabel L80243244_BE69F4
/* BE69F4 80243244 0260202D */  daddu     $a0, $s3, $zero
/* BE69F8 80243248 0280282D */  daddu     $a1, $s4, $zero
/* BE69FC 8024324C 0C012849 */  jal       func_8004A124
/* BE6A00 80243250 0200302D */   daddu    $a2, $s0, $zero
/* BE6A04 80243254 8E630070 */  lw        $v1, 0x70($s3)
/* BE6A08 80243258 2402000E */  addiu     $v0, $zero, 0xe
/* BE6A0C 8024325C 14620039 */  bne       $v1, $v0, .L80243344
/* BE6A10 80243260 0000102D */   daddu    $v0, $zero, $zero
glabel L80243264_BE6A14
/* BE6A14 80243264 96A2008E */  lhu       $v0, 0x8e($s5)
/* BE6A18 80243268 2442FFFF */  addiu     $v0, $v0, -1
/* BE6A1C 8024326C A6A2008E */  sh        $v0, 0x8e($s5)
/* BE6A20 80243270 00021400 */  sll       $v0, $v0, 0x10
/* BE6A24 80243274 14400033 */  bnez      $v0, .L80243344
/* BE6A28 80243278 0000102D */   daddu    $v0, $zero, $zero
/* BE6A2C 8024327C 24020028 */  addiu     $v0, $zero, 0x28
/* BE6A30 80243280 08090CD0 */  j         L80243340_BE6AF0
/* BE6A34 80243284 AE620070 */   sw       $v0, 0x70($s3)
glabel L80243288_BE6A38
/* BE6A38 80243288 0260202D */  daddu     $a0, $s3, $zero
/* BE6A3C 8024328C 0280282D */  daddu     $a1, $s4, $zero
/* BE6A40 80243290 0C090A73 */  jal       arn_04_UnkNpcAIFunc16
/* BE6A44 80243294 0200302D */   daddu    $a2, $s0, $zero
glabel L80243298_BE6A48
/* BE6A48 80243298 0260202D */  daddu     $a0, $s3, $zero
/* BE6A4C 8024329C 0280282D */  daddu     $a1, $s4, $zero
/* BE6A50 802432A0 0C090A87 */  jal       func_80242A1C_BE61CC
/* BE6A54 802432A4 0200302D */   daddu    $a2, $s0, $zero
/* BE6A58 802432A8 08090CD1 */  j         .L80243344
/* BE6A5C 802432AC 0000102D */   daddu    $v0, $zero, $zero
glabel L802432B0_BE6A60
/* BE6A60 802432B0 0260202D */  daddu     $a0, $s3, $zero
/* BE6A64 802432B4 0280282D */  daddu     $a1, $s4, $zero
/* BE6A68 802432B8 0C090AEF */  jal       func_80242BBC_BE636C
/* BE6A6C 802432BC 0200302D */   daddu    $a2, $s0, $zero
/* BE6A70 802432C0 08090CD1 */  j         .L80243344
/* BE6A74 802432C4 0000102D */   daddu    $v0, $zero, $zero
glabel L802432C8_BE6A78
/* BE6A78 802432C8 0260202D */  daddu     $a0, $s3, $zero
/* BE6A7C 802432CC 0280282D */  daddu     $a1, $s4, $zero
/* BE6A80 802432D0 0C090B43 */  jal       func_80242D0C_BE64BC
/* BE6A84 802432D4 0200302D */   daddu    $a2, $s0, $zero
/* BE6A88 802432D8 8E630070 */  lw        $v1, 0x70($s3)
/* BE6A8C 802432DC 24020029 */  addiu     $v0, $zero, 0x29
/* BE6A90 802432E0 14620018 */  bne       $v1, $v0, .L80243344
/* BE6A94 802432E4 0000102D */   daddu    $v0, $zero, $zero
glabel L802432E8_BE6A98
/* BE6A98 802432E8 0260202D */  daddu     $a0, $s3, $zero
/* BE6A9C 802432EC 0280282D */  daddu     $a1, $s4, $zero
/* BE6AA0 802432F0 0C090B6E */  jal       func_80242DB8_BE6568
/* BE6AA4 802432F4 0200302D */   daddu    $a2, $s0, $zero
/* BE6AA8 802432F8 08090CD1 */  j         .L80243344
/* BE6AAC 802432FC 0000102D */   daddu    $v0, $zero, $zero
glabel L80243300_BE6AB0
/* BE6AB0 80243300 0260202D */  daddu     $a0, $s3, $zero
/* BE6AB4 80243304 0280282D */  daddu     $a1, $s4, $zero
/* BE6AB8 80243308 0C090BBC */  jal       arn_04_UnkNpcAIFunc19
/* BE6ABC 8024330C 0200302D */   daddu    $a2, $s0, $zero
glabel L80243310_BE6AC0
/* BE6AC0 80243310 0260202D */  daddu     $a0, $s3, $zero
/* BE6AC4 80243314 0280282D */  daddu     $a1, $s4, $zero
/* BE6AC8 80243318 0C090BDB */  jal       arn_04_UnkNpcAIFunc17
/* BE6ACC 8024331C 0200302D */   daddu    $a2, $s0, $zero
/* BE6AD0 80243320 8E630070 */  lw        $v1, 0x70($s3)
/* BE6AD4 80243324 24020034 */  addiu     $v0, $zero, 0x34
/* BE6AD8 80243328 14620006 */  bne       $v1, $v0, .L80243344
/* BE6ADC 8024332C 0000102D */   daddu    $v0, $zero, $zero
glabel L80243330_BE6AE0
/* BE6AE0 80243330 0260202D */  daddu     $a0, $s3, $zero
/* BE6AE4 80243334 0280282D */  daddu     $a1, $s4, $zero
/* BE6AE8 80243338 0C090BF5 */  jal       arn_04_UnkDurationCheck
/* BE6AEC 8024333C 0200302D */   daddu    $a2, $s0, $zero
glabel L80243340_BE6AF0
/* BE6AF0 80243340 0000102D */  daddu     $v0, $zero, $zero
.L80243344:
/* BE6AF4 80243344 8FBF0048 */  lw        $ra, 0x48($sp)
/* BE6AF8 80243348 8FB50044 */  lw        $s5, 0x44($sp)
/* BE6AFC 8024334C 8FB40040 */  lw        $s4, 0x40($sp)
/* BE6B00 80243350 8FB3003C */  lw        $s3, 0x3c($sp)
/* BE6B04 80243354 8FB20038 */  lw        $s2, 0x38($sp)
/* BE6B08 80243358 8FB10034 */  lw        $s1, 0x34($sp)
/* BE6B0C 8024335C 8FB00030 */  lw        $s0, 0x30($sp)
/* BE6B10 80243360 03E00008 */  jr        $ra
/* BE6B14 80243364 27BD0050 */   addiu    $sp, $sp, 0x50
/* BE6B18 80243368 00000000 */  nop
/* BE6B1C 8024336C 00000000 */  nop
