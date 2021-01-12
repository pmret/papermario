.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241134_B21674
/* B21674 80241134 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B21678 80241138 AFBF0018 */  sw        $ra, 0x18($sp)
/* B2167C 8024113C 0C00EAD2 */  jal       get_npc_safe
/* B21680 80241140 24040002 */   addiu    $a0, $zero, 2
/* B21684 80241144 C4420040 */  lwc1      $f2, 0x40($v0)
/* B21688 80241148 3C0141A0 */  lui       $at, 0x41a0
/* B2168C 8024114C 44810000 */  mtc1      $at, $f0
/* B21690 80241150 C444003C */  lwc1      $f4, 0x3c($v0)
/* B21694 80241154 46001081 */  sub.s     $f2, $f2, $f0
/* B21698 80241158 44803000 */  mtc1      $zero, $f6
/* B2169C 8024115C 00000000 */  nop
/* B216A0 80241160 4606203C */  c.lt.s    $f4, $f6
/* B216A4 80241164 C4400038 */  lwc1      $f0, 0x38($v0)
/* B216A8 80241168 45000006 */  bc1f      .L80241184
/* B216AC 8024116C 0000202D */   daddu    $a0, $zero, $zero
/* B216B0 80241170 44050000 */  mfc1      $a1, $f0
/* B216B4 80241174 44062000 */  mfc1      $a2, $f4
/* B216B8 80241178 44071000 */  mfc1      $a3, $f2
/* B216BC 8024117C 0C01C16C */  jal       func_800705B0
/* B216C0 80241180 E7A60010 */   swc1     $f6, 0x10($sp)
.L80241184:
/* B216C4 80241184 8FBF0018 */  lw        $ra, 0x18($sp)
/* B216C8 80241188 0000102D */  daddu     $v0, $zero, $zero
/* B216CC 8024118C 03E00008 */  jr        $ra
/* B216D0 80241190 27BD0020 */   addiu    $sp, $sp, 0x20
/* B216D4 80241194 00000000 */  nop
/* B216D8 80241198 00000000 */  nop
/* B216DC 8024119C 00000000 */  nop
