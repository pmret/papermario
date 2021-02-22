.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8028035C
/* 7E11DC 8028035C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 7E11E0 80280360 3C048028 */  lui       $a0, %hi(D_80283F2C)
/* 7E11E4 80280364 24843F2C */  addiu     $a0, $a0, %lo(D_80283F2C)
/* 7E11E8 80280368 24050001 */  addiu     $a1, $zero, 1
/* 7E11EC 8028036C 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 7E11F0 80280370 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 7E11F4 80280374 AFBF0014 */  sw        $ra, 0x14($sp)
/* 7E11F8 80280378 AFB00010 */  sw        $s0, 0x10($sp)
/* 7E11FC 8028037C 8C500144 */  lw        $s0, 0x144($v0)
/* 7E1200 80280380 0C0B0CF8 */  jal       start_script
/* 7E1204 80280384 0000302D */   daddu    $a2, $zero, $zero
/* 7E1208 80280388 8E030010 */  lw        $v1, 0x10($s0)
/* 7E120C 8028038C 8C630000 */  lw        $v1, ($v1)
/* 7E1210 80280390 0040202D */  daddu     $a0, $v0, $zero
/* 7E1214 80280394 AC830084 */  sw        $v1, 0x84($a0)
/* 7E1218 80280398 8E020010 */  lw        $v0, 0x10($s0)
/* 7E121C 8028039C 8C420008 */  lw        $v0, 8($v0)
/* 7E1220 802803A0 AC820088 */  sw        $v0, 0x88($a0)
/* 7E1224 802803A4 8E030010 */  lw        $v1, 0x10($s0)
/* 7E1228 802803A8 8C820144 */  lw        $v0, 0x144($a0)
/* 7E122C 802803AC 8C630004 */  lw        $v1, 4($v1)
/* 7E1230 802803B0 AC83008C */  sw        $v1, 0x8c($a0)
/* 7E1234 802803B4 AC83007C */  sw        $v1, 0x7c($a0)
/* 7E1238 802803B8 8FBF0014 */  lw        $ra, 0x14($sp)
/* 7E123C 802803BC 8FB00010 */  lw        $s0, 0x10($sp)
/* 7E1240 802803C0 03E00008 */  jr        $ra
/* 7E1244 802803C4 27BD0018 */   addiu    $sp, $sp, 0x18
