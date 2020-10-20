.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242978
/* C38EA8 80242978 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* C38EAC 8024297C AFBF0018 */  sw        $ra, 0x18($sp)
/* C38EB0 80242980 0C00EAD2 */  jal       get_npc_safe
/* C38EB4 80242984 2404FFFC */   addiu    $a0, $zero, -4
/* C38EB8 80242988 C444003C */  lwc1      $f4, 0x3c($v0)
/* C38EBC 8024298C 3C014148 */  lui       $at, 0x4148
/* C38EC0 80242990 44811000 */  mtc1      $at, $f2
/* C38EC4 80242994 3C013F80 */  lui       $at, 0x3f80
/* C38EC8 80242998 44810000 */  mtc1      $at, $f0
/* C38ECC 8024299C 2403001E */  addiu     $v1, $zero, 0x1e
/* C38ED0 802429A0 AFA30014 */  sw        $v1, 0x14($sp)
/* C38ED4 802429A4 46022100 */  add.s     $f4, $f4, $f2
/* C38ED8 802429A8 E7A00010 */  swc1      $f0, 0x10($sp)
/* C38EDC 802429AC 8C450038 */  lw        $a1, 0x38($v0)
/* C38EE0 802429B0 8C470040 */  lw        $a3, 0x40($v0)
/* C38EE4 802429B4 44062000 */  mfc1      $a2, $f4
/* C38EE8 802429B8 0C01C2EC */  jal       func_80070BB0
/* C38EEC 802429BC 24040009 */   addiu    $a0, $zero, 9
/* C38EF0 802429C0 8FBF0018 */  lw        $ra, 0x18($sp)
/* C38EF4 802429C4 24020002 */  addiu     $v0, $zero, 2
/* C38EF8 802429C8 03E00008 */  jr        $ra
/* C38EFC 802429CC 27BD0020 */   addiu    $sp, $sp, 0x20
