.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802802D0
/* 7E1150 802802D0 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E1154 802802D4 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E1158 802802D8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 7E115C 802802DC AFBF0018 */  sw        $ra, 0x18($sp)
/* 7E1160 802802E0 AFB10014 */  sw        $s1, 0x14($sp)
/* 7E1164 802802E4 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E1168 802802E8 8C510144 */  lw        $s1, 0x144($v0)
/* 7E116C 802802EC 24050001 */  addiu     $a1, $zero, 1
/* 7E1170 802802F0 8E220010 */  lw        $v0, 0x10($s1)
/* 7E1174 802802F4 8C430018 */  lw        $v1, 0x18($v0)
/* 7E1178 802802F8 00041080 */  sll       $v0, $a0, 2
/* 7E117C 802802FC 3C048028 */  lui       $a0, 0x8028
/* 7E1180 80280300 24843EE0 */  addiu     $a0, $a0, 0x3ee0
/* 7E1184 80280304 00431021 */  addu      $v0, $v0, $v1
/* 7E1188 80280308 8C500000 */  lw        $s0, ($v0)
/* 7E118C 8028030C 0C0B0CF8 */  jal       start_script
/* 7E1190 80280310 0000302D */   daddu    $a2, $zero, $zero
/* 7E1194 80280314 0040202D */  daddu     $a0, $v0, $zero
/* 7E1198 80280318 AC900084 */  sw        $s0, 0x84($a0)
/* 7E119C 8028031C 8E220010 */  lw        $v0, 0x10($s1)
/* 7E11A0 80280320 8C420000 */  lw        $v0, ($v0)
/* 7E11A4 80280324 AC820088 */  sw        $v0, 0x88($a0)
/* 7E11A8 80280328 8E220010 */  lw        $v0, 0x10($s1)
/* 7E11AC 8028032C 8C420008 */  lw        $v0, 8($v0)
/* 7E11B0 80280330 AC82008C */  sw        $v0, 0x8c($a0)
/* 7E11B4 80280334 8E230010 */  lw        $v1, 0x10($s1)
/* 7E11B8 80280338 8C820144 */  lw        $v0, 0x144($a0)
/* 7E11BC 8028033C 8C630004 */  lw        $v1, 4($v1)
/* 7E11C0 80280340 AC830090 */  sw        $v1, 0x90($a0)
/* 7E11C4 80280344 AC83007C */  sw        $v1, 0x7c($a0)
/* 7E11C8 80280348 8FBF0018 */  lw        $ra, 0x18($sp)
/* 7E11CC 8028034C 8FB10014 */  lw        $s1, 0x14($sp)
/* 7E11D0 80280350 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E11D4 80280354 03E00008 */  jr        $ra
/* 7E11D8 80280358 27BD0020 */   addiu    $sp, $sp, 0x20
