.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8002C870
/* 7C70 8002C870 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 7C74 8002C874 3C07FFFD */  lui       $a3, 0xfffd
/* 7C78 8002C878 34E7A800 */  ori       $a3, $a3, 0xa800
/* 7C7C 8002C87C AFB00018 */  sw        $s0, 0x18($sp)
/* 7C80 8002C880 3C10800A */  lui       $s0, %hi(D_8009BB10)
/* 7C84 8002C884 2610BB10 */  addiu     $s0, $s0, %lo(D_8009BB10)
/* 7C88 8002C888 AFB1001C */  sw        $s1, 0x1c($sp)
/* 7C8C 8002C88C 261109B0 */  addiu     $s1, $s0, 0x9b0
/* 7C90 8002C890 0220202D */  daddu     $a0, $s1, $zero
/* 7C94 8002C894 260509C8 */  addiu     $a1, $s0, 0x9c8
/* 7C98 8002C898 24060001 */  addiu     $a2, $zero, 1
/* 7C9C 8002C89C 24020140 */  addiu     $v0, $zero, 0x140
/* 7CA0 8002C8A0 AFBF0020 */  sw        $ra, 0x20($sp)
/* 7CA4 8002C8A4 A60209D0 */  sh        $v0, 0x9d0($s0)
/* 7CA8 8002C8A8 24020010 */  addiu     $v0, $zero, 0x10
/* 7CAC 8002C8AC A60209D2 */  sh        $v0, 0x9d2($s0)
/* 7CB0 8002C8B0 3C028000 */  lui       $v0, %hi(D_80000318)
/* 7CB4 8002C8B4 8C420318 */  lw        $v0, %lo(D_80000318)($v0)
/* 7CB8 8002C8B8 3C03A000 */  lui       $v1, 0xa000
/* 7CBC 8002C8BC 00431025 */  or        $v0, $v0, $v1
/* 7CC0 8002C8C0 00471021 */  addu      $v0, $v0, $a3
/* 7CC4 8002C8C4 0C019554 */  jal       func_80065550
/* 7CC8 8002C8C8 AE0209CC */   sw       $v0, 0x9cc($s0)
/* 7CCC 8002C8CC 0200202D */  daddu     $a0, $s0, $zero
/* 7CD0 8002C8D0 24050002 */  addiu     $a1, $zero, 2
/* 7CD4 8002C8D4 3C068003 */  lui       $a2, %hi(func_8002C7DC)
/* 7CD8 8002C8D8 24C6C7DC */  addiu     $a2, $a2, %lo(func_8002C7DC)
/* 7CDC 8002C8DC 24020080 */  addiu     $v0, $zero, 0x80
/* 7CE0 8002C8E0 0000382D */  daddu     $a3, $zero, $zero
/* 7CE4 8002C8E4 AFB10010 */  sw        $s1, 0x10($sp)
/* 7CE8 8002C8E8 0C01978C */  jal       func_80065E30
/* 7CEC 8002C8EC AFA20014 */   sw       $v0, 0x14($sp)
/* 7CF0 8002C8F0 0C0197FC */  jal       func_80065FF0
/* 7CF4 8002C8F4 0200202D */   daddu    $a0, $s0, $zero
/* 7CF8 8002C8F8 8FBF0020 */  lw        $ra, 0x20($sp)
/* 7CFC 8002C8FC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 7D00 8002C900 8FB00018 */  lw        $s0, 0x18($sp)
/* 7D04 8002C904 03E00008 */  jr        $ra
/* 7D08 8002C908 27BD0028 */   addiu    $sp, $sp, 0x28
