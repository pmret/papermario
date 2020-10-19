.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C10_BC8A70
/* BC8A70 80240C10 3C0142FA */  lui       $at, 0x42fa
/* BC8A74 80240C14 44810000 */  mtc1      $at, $f0
/* BC8A78 80240C18 27BDFCA8 */  addiu     $sp, $sp, -0x358
/* BC8A7C 80240C1C AFB00350 */  sw        $s0, 0x350($sp)
/* BC8A80 80240C20 0080802D */  daddu     $s0, $a0, $zero
/* BC8A84 80240C24 AFBF0354 */  sw        $ra, 0x354($sp)
/* BC8A88 80240C28 AFA00048 */  sw        $zero, 0x48($sp)
/* BC8A8C 80240C2C AFA0004C */  sw        $zero, 0x4c($sp)
/* BC8A90 80240C30 AFA00050 */  sw        $zero, 0x50($sp)
/* BC8A94 80240C34 E7A00020 */  swc1      $f0, 0x20($sp)
/* BC8A98 80240C38 C6040084 */  lwc1      $f4, 0x84($s0)
/* BC8A9C 80240C3C 46802120 */  cvt.s.w   $f4, $f4
/* BC8AA0 80240C40 44050000 */  mfc1      $a1, $f0
/* BC8AA4 80240C44 44062000 */  mfc1      $a2, $f4
/* BC8AA8 80240C48 0C00EA95 */  jal       npc_move_heading
/* BC8AAC 80240C4C 27A40010 */   addiu    $a0, $sp, 0x10
/* BC8AB0 80240C50 C7A00048 */  lwc1      $f0, 0x48($sp)
/* BC8AB4 80240C54 3C014120 */  lui       $at, 0x4120
/* BC8AB8 80240C58 44811000 */  mtc1      $at, $f2
/* BC8ABC 80240C5C 4600010D */  trunc.w.s $f4, $f0
/* BC8AC0 80240C60 E6040084 */  swc1      $f4, 0x84($s0)
/* BC8AC4 80240C64 C7A0004C */  lwc1      $f0, 0x4c($sp)
/* BC8AC8 80240C68 46020000 */  add.s     $f0, $f0, $f2
/* BC8ACC 80240C6C 3C0141A0 */  lui       $at, 0x41a0
/* BC8AD0 80240C70 44811000 */  mtc1      $at, $f2
/* BC8AD4 80240C74 4600010D */  trunc.w.s $f4, $f0
/* BC8AD8 80240C78 E6040088 */  swc1      $f4, 0x88($s0)
/* BC8ADC 80240C7C C7A00050 */  lwc1      $f0, 0x50($sp)
/* BC8AE0 80240C80 46020000 */  add.s     $f0, $f0, $f2
/* BC8AE4 80240C84 4600010D */  trunc.w.s $f4, $f0
/* BC8AE8 80240C88 E604008C */  swc1      $f4, 0x8c($s0)
/* BC8AEC 80240C8C 8FBF0354 */  lw        $ra, 0x354($sp)
/* BC8AF0 80240C90 8FB00350 */  lw        $s0, 0x350($sp)
/* BC8AF4 80240C94 24020002 */  addiu     $v0, $zero, 2
/* BC8AF8 80240C98 03E00008 */  jr        $ra
/* BC8AFC 80240C9C 27BD0358 */   addiu    $sp, $sp, 0x358
