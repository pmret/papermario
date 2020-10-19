.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240C08_B5EEB8
/* B5EEB8 80240C08 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* B5EEBC 80240C0C AFBF0018 */  sw        $ra, 0x18($sp)
/* B5EEC0 80240C10 0C00EAD2 */  jal       get_npc_safe
/* B5EEC4 80240C14 2404FFFC */   addiu    $a0, $zero, -4
/* B5EEC8 80240C18 C444003C */  lwc1      $f4, 0x3c($v0)
/* B5EECC 80240C1C 3C014148 */  lui       $at, 0x4148
/* B5EED0 80240C20 44811000 */  mtc1      $at, $f2
/* B5EED4 80240C24 3C013F80 */  lui       $at, 0x3f80
/* B5EED8 80240C28 44810000 */  mtc1      $at, $f0
/* B5EEDC 80240C2C 2403001E */  addiu     $v1, $zero, 0x1e
/* B5EEE0 80240C30 AFA30014 */  sw        $v1, 0x14($sp)
/* B5EEE4 80240C34 46022100 */  add.s     $f4, $f4, $f2
/* B5EEE8 80240C38 E7A00010 */  swc1      $f0, 0x10($sp)
/* B5EEEC 80240C3C 8C450038 */  lw        $a1, 0x38($v0)
/* B5EEF0 80240C40 8C470040 */  lw        $a3, 0x40($v0)
/* B5EEF4 80240C44 44062000 */  mfc1      $a2, $f4
/* B5EEF8 80240C48 0C01C2EC */  jal       func_80070BB0
/* B5EEFC 80240C4C 24040009 */   addiu    $a0, $zero, 9
/* B5EF00 80240C50 8FBF0018 */  lw        $ra, 0x18($sp)
/* B5EF04 80240C54 24020002 */  addiu     $v0, $zero, 2
/* B5EF08 80240C58 03E00008 */  jr        $ra
/* B5EF0C 80240C5C 27BD0020 */   addiu    $sp, $sp, 0x20
