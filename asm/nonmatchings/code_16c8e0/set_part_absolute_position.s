.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_part_absolute_position
/* 198550 80269C70 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 198554 80269C74 F7B40020 */  sdc1      $f20, 0x20($sp)
/* 198558 80269C78 4486A000 */  mtc1      $a2, $f20
/* 19855C 80269C7C F7B60028 */  sdc1      $f22, 0x28($sp)
/* 198560 80269C80 4487B000 */  mtc1      $a3, $f22
/* 198564 80269C84 AFB00010 */  sw        $s0, 0x10($sp)
/* 198568 80269C88 0080802D */  daddu     $s0, $a0, $zero
/* 19856C 80269C8C AFB10014 */  sw        $s1, 0x14($sp)
/* 198570 80269C90 F7B80030 */  sdc1      $f24, 0x30($sp)
/* 198574 80269C94 C7B80048 */  lwc1      $f24, 0x48($sp)
/* 198578 80269C98 AFBF0018 */  sw        $ra, 0x18($sp)
/* 19857C 80269C9C 0C09A75B */  jal       get_actor
/* 198580 80269CA0 00A0882D */   daddu    $s1, $a1, $zero
/* 198584 80269CA4 0040202D */  daddu     $a0, $v0, $zero
/* 198588 80269CA8 32100700 */  andi      $s0, $s0, 0x700
/* 19858C 80269CAC 24020100 */  addiu     $v0, $zero, 0x100
/* 198590 80269CB0 1202000E */  beq       $s0, $v0, .L80269CEC
/* 198594 80269CB4 2A020101 */   slti     $v0, $s0, 0x101
/* 198598 80269CB8 50400005 */  beql      $v0, $zero, .L80269CD0
/* 19859C 80269CBC 24020200 */   addiu    $v0, $zero, 0x200
/* 1985A0 80269CC0 52000007 */  beql      $s0, $zero, .L80269CE0
/* 1985A4 80269CC4 E4940144 */   swc1     $f20, 0x144($a0)
/* 1985A8 80269CC8 0809A740 */  j         .L80269D00
/* 1985AC 80269CCC 00000000 */   nop      
.L80269CD0:
/* 1985B0 80269CD0 12020006 */  beq       $s0, $v0, .L80269CEC
/* 1985B4 80269CD4 00000000 */   nop      
/* 1985B8 80269CD8 0809A740 */  j         .L80269D00
/* 1985BC 80269CDC 00000000 */   nop      
.L80269CE0:
/* 1985C0 80269CE0 E4960148 */  swc1      $f22, 0x148($a0)
/* 1985C4 80269CE4 0809A740 */  j         .L80269D00
/* 1985C8 80269CE8 E498014C */   swc1     $f24, 0x14c($a0)
.L80269CEC:
/* 1985CC 80269CEC 0C099117 */  jal       get_actor_part
/* 1985D0 80269CF0 0220282D */   daddu    $a1, $s1, $zero
/* 1985D4 80269CF4 E454002C */  swc1      $f20, 0x2c($v0)
/* 1985D8 80269CF8 E4560030 */  swc1      $f22, 0x30($v0)
/* 1985DC 80269CFC E4580034 */  swc1      $f24, 0x34($v0)
.L80269D00:
/* 1985E0 80269D00 8FBF0018 */  lw        $ra, 0x18($sp)
/* 1985E4 80269D04 8FB10014 */  lw        $s1, 0x14($sp)
/* 1985E8 80269D08 8FB00010 */  lw        $s0, 0x10($sp)
/* 1985EC 80269D0C D7B80030 */  ldc1      $f24, 0x30($sp)
/* 1985F0 80269D10 D7B60028 */  ldc1      $f22, 0x28($sp)
/* 1985F4 80269D14 D7B40020 */  ldc1      $f20, 0x20($sp)
/* 1985F8 80269D18 03E00008 */  jr        $ra
/* 1985FC 80269D1C 27BD0038 */   addiu    $sp, $sp, 0x38
