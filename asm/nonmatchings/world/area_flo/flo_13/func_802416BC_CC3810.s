.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802416BC_CC4ECC
/* CC4ECC 802416BC 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* CC4ED0 802416C0 AFB00010 */  sw        $s0, 0x10($sp)
/* CC4ED4 802416C4 24100032 */  addiu     $s0, $zero, 0x32
/* CC4ED8 802416C8 AFBF0014 */  sw        $ra, 0x14($sp)
.L802416CC:
/* CC4EDC 802416CC 0C00FB3A */  jal       get_enemy
/* CC4EE0 802416D0 0200202D */   daddu    $a0, $s0, $zero
/* CC4EE4 802416D4 8C420094 */  lw        $v0, 0x94($v0)
/* CC4EE8 802416D8 54400003 */  bnel      $v0, $zero, .L802416E8
/* CC4EEC 802416DC 26100001 */   addiu    $s0, $s0, 1
/* CC4EF0 802416E0 080905BD */  j         .L802416F4
/* CC4EF4 802416E4 0200102D */   daddu    $v0, $s0, $zero
.L802416E8:
/* CC4EF8 802416E8 2A020038 */  slti      $v0, $s0, 0x38
/* CC4EFC 802416EC 1440FFF7 */  bnez      $v0, .L802416CC
/* CC4F00 802416F0 2402FFFF */   addiu    $v0, $zero, -1
.L802416F4:
/* CC4F04 802416F4 8FBF0014 */  lw        $ra, 0x14($sp)
/* CC4F08 802416F8 8FB00010 */  lw        $s0, 0x10($sp)
/* CC4F0C 802416FC 03E00008 */  jr        $ra
/* CC4F10 80241700 27BD0018 */   addiu    $sp, $sp, 0x18
