.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel omo_11_UnkFunc22
/* DDD568 80240D38 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DDD56C 80240D3C AFBF0018 */  sw        $ra, 0x18($sp)
/* DDD570 80240D40 0C00EAD2 */  jal       get_npc_safe
/* DDD574 80240D44 2404FFFC */   addiu    $a0, $zero, -4
/* DDD578 80240D48 C444003C */  lwc1      $f4, 0x3c($v0)
/* DDD57C 80240D4C 3C014148 */  lui       $at, 0x4148
/* DDD580 80240D50 44811000 */  mtc1      $at, $f2
/* DDD584 80240D54 3C013F80 */  lui       $at, 0x3f80
/* DDD588 80240D58 44810000 */  mtc1      $at, $f0
/* DDD58C 80240D5C 2403001E */  addiu     $v1, $zero, 0x1e
/* DDD590 80240D60 AFA30014 */  sw        $v1, 0x14($sp)
/* DDD594 80240D64 46022100 */  add.s     $f4, $f4, $f2
/* DDD598 80240D68 E7A00010 */  swc1      $f0, 0x10($sp)
/* DDD59C 80240D6C 8C450038 */  lw        $a1, 0x38($v0)
/* DDD5A0 80240D70 8C470040 */  lw        $a3, 0x40($v0)
/* DDD5A4 80240D74 44062000 */  mfc1      $a2, $f4
/* DDD5A8 80240D78 0C01C2EC */  jal       func_80070BB0
/* DDD5AC 80240D7C 24040009 */   addiu    $a0, $zero, 9
/* DDD5B0 80240D80 8FBF0018 */  lw        $ra, 0x18($sp)
/* DDD5B4 80240D84 24020002 */  addiu     $v0, $zero, 2
/* DDD5B8 80240D88 03E00008 */  jr        $ra
/* DDD5BC 80240D8C 27BD0020 */   addiu    $sp, $sp, 0x20
