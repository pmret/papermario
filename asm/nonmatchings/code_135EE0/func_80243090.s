.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243090
/* 1363D0 80243090 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 1363D4 80243094 3C028016 */  lui       $v0, %hi(gUIPanels)
/* 1363D8 80243098 24429D50 */  addiu     $v0, $v0, %lo(gUIPanels)
/* 1363DC 8024309C 00041940 */  sll       $v1, $a0, 5
/* 1363E0 802430A0 AFB00010 */  sw        $s0, 0x10($sp)
/* 1363E4 802430A4 00628021 */  addu      $s0, $v1, $v0
/* 1363E8 802430A8 AFBF0014 */  sw        $ra, 0x14($sp)
/* 1363EC 802430AC 9202001C */  lbu       $v0, 0x1c($s0)
/* 1363F0 802430B0 14400008 */  bnez      $v0, .L802430D4
/* 1363F4 802430B4 00000000 */   nop
/* 1363F8 802430B8 0C051F5C */  jal       func_80147D70
/* 1363FC 802430BC 92050002 */   lbu      $a1, 2($s0)
/* 136400 802430C0 8FA20040 */  lw        $v0, 0x40($sp)
/* 136404 802430C4 AC400000 */  sw        $zero, ($v0)
/* 136408 802430C8 92020000 */  lbu       $v0, ($s0)
/* 13640C 802430CC 304200F7 */  andi      $v0, $v0, 0xf7
/* 136410 802430D0 A2020000 */  sb        $v0, ($s0)
.L802430D4:
/* 136414 802430D4 8FBF0014 */  lw        $ra, 0x14($sp)
/* 136418 802430D8 8FB00010 */  lw        $s0, 0x10($sp)
/* 13641C 802430DC 03E00008 */  jr        $ra
/* 136420 802430E0 27BD0018 */   addiu    $sp, $sp, 0x18
