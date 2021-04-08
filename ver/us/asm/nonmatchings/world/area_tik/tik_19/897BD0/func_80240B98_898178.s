.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel tik_19_UnkFunc22
/* 898178 80240B98 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 89817C 80240B9C AFBF0018 */  sw        $ra, 0x18($sp)
/* 898180 80240BA0 0C00EAD2 */  jal       get_npc_safe
/* 898184 80240BA4 2404FFFC */   addiu    $a0, $zero, -4
/* 898188 80240BA8 C444003C */  lwc1      $f4, 0x3c($v0)
/* 89818C 80240BAC 3C014148 */  lui       $at, 0x4148
/* 898190 80240BB0 44811000 */  mtc1      $at, $f2
/* 898194 80240BB4 3C013F80 */  lui       $at, 0x3f80
/* 898198 80240BB8 44810000 */  mtc1      $at, $f0
/* 89819C 80240BBC 2403001E */  addiu     $v1, $zero, 0x1e
/* 8981A0 80240BC0 AFA30014 */  sw        $v1, 0x14($sp)
/* 8981A4 80240BC4 46022100 */  add.s     $f4, $f4, $f2
/* 8981A8 80240BC8 E7A00010 */  swc1      $f0, 0x10($sp)
/* 8981AC 80240BCC 8C450038 */  lw        $a1, 0x38($v0)
/* 8981B0 80240BD0 8C470040 */  lw        $a3, 0x40($v0)
/* 8981B4 80240BD4 44062000 */  mfc1      $a2, $f4
/* 8981B8 80240BD8 0C01C2EC */  jal       func_80070BB0
/* 8981BC 80240BDC 24040009 */   addiu    $a0, $zero, 9
/* 8981C0 80240BE0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 8981C4 80240BE4 24020002 */  addiu     $v0, $zero, 2
/* 8981C8 80240BE8 03E00008 */  jr        $ra
/* 8981CC 80240BEC 27BD0020 */   addiu    $sp, $sp, 0x20
