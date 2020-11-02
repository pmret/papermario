.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80280208
/* 7E1088 80280208 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E108C 8028020C 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E1090 80280210 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E1094 80280214 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E1098 80280218 00A0802D */  daddu     $s0, $a1, $zero
/* 7E109C 8028021C AFBF001C */  sw        $ra, 0x1c($sp)
/* 7E10A0 80280220 AFB20018 */  sw        $s2, 0x18($sp)
/* 7E10A4 80280224 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E10A8 80280228 8C510144 */  lw        $s1, 0x144($v0)
/* 7E10AC 8028022C 0000282D */  daddu     $a1, $zero, $zero
/* 7E10B0 80280230 8E230010 */  lw        $v1, 0x10($s1)
/* 7E10B4 80280234 00041080 */  sll       $v0, $a0, 2
/* 7E10B8 80280238 8C630018 */  lw        $v1, 0x18($v1)
/* 7E10BC 8028023C 00431021 */  addu      $v0, $v0, $v1
/* 7E10C0 80280240 8C520000 */  lw        $s2, ($v0)
/* 7E10C4 80280244 0C0496FA */  jal       set_message_value
/* 7E10C8 80280248 0200202D */   daddu    $a0, $s0, $zero
/* 7E10CC 8028024C 3C048015 */  lui       $a0, 0x8015
/* 7E10D0 80280250 2484C290 */  addiu     $a0, $a0, -0x3d70
/* 7E10D4 80280254 24020001 */  addiu     $v0, $zero, 1
/* 7E10D8 80280258 16020003 */  bne       $s0, $v0, .L80280268
/* 7E10DC 8028025C 00000000 */   nop      
/* 7E10E0 80280260 3C048015 */  lui       $a0, 0x8015
/* 7E10E4 80280264 2484C294 */  addiu     $a0, $a0, -0x3d6c
.L80280268:
/* 7E10E8 80280268 0C0496CF */  jal       set_message_string
/* 7E10EC 8028026C 24050001 */   addiu    $a1, $zero, 1
/* 7E10F0 80280270 3C048028 */  lui       $a0, 0x8028
/* 7E10F4 80280274 24843EB0 */  addiu     $a0, $a0, 0x3eb0
/* 7E10F8 80280278 24050001 */  addiu     $a1, $zero, 1
/* 7E10FC 8028027C 0C0B0CF8 */  jal       start_script
/* 7E1100 80280280 0000302D */   daddu    $a2, $zero, $zero
/* 7E1104 80280284 0040202D */  daddu     $a0, $v0, $zero
/* 7E1108 80280288 AC920084 */  sw        $s2, 0x84($a0)
/* 7E110C 8028028C 8E220010 */  lw        $v0, 0x10($s1)
/* 7E1110 80280290 8C420000 */  lw        $v0, ($v0)
/* 7E1114 80280294 AC820088 */  sw        $v0, 0x88($a0)
/* 7E1118 80280298 8E220010 */  lw        $v0, 0x10($s1)
/* 7E111C 8028029C 8C420008 */  lw        $v0, 8($v0)
/* 7E1120 802802A0 AC82008C */  sw        $v0, 0x8c($a0)
/* 7E1124 802802A4 8E230010 */  lw        $v1, 0x10($s1)
/* 7E1128 802802A8 8C820144 */  lw        $v0, 0x144($a0)
/* 7E112C 802802AC 8C630004 */  lw        $v1, 4($v1)
/* 7E1130 802802B0 AC830090 */  sw        $v1, 0x90($a0)
/* 7E1134 802802B4 AC83007C */  sw        $v1, 0x7c($a0)
/* 7E1138 802802B8 8FBF001C */  lw        $ra, 0x1c($sp)
/* 7E113C 802802BC 8FB20018 */  lw        $s2, 0x18($sp)
/* 7E1140 802802C0 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E1144 802802C4 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E1148 802802C8 03E00008 */  jr        $ra
/* 7E114C 802802CC 27BD0020 */   addiu    $sp, $sp, 0x20
