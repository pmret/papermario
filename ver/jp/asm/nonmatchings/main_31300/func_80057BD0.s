.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80057BD0
/* 32FD0 80057BD0 30A3000F */  andi      $v1, $a1, 0xf
/* 32FD4 80057BD4 24020010 */  addiu     $v0, $zero, 0x10
/* 32FD8 80057BD8 00431823 */  subu      $v1, $v0, $v1
/* 32FDC 80057BDC 10620003 */  beq       $v1, $v0, .L80057BEC
/* 32FE0 80057BE0 00A31021 */   addu     $v0, $a1, $v1
/* 32FE4 80057BE4 08015EFC */  j         .L80057BF0
/* 32FE8 80057BE8 AC820000 */   sw       $v0, ($a0)
.L80057BEC:
/* 32FEC 80057BEC AC850000 */  sw        $a1, ($a0)
.L80057BF0:
/* 32FF0 80057BF0 AC860008 */  sw        $a2, 8($a0)
/* 32FF4 80057BF4 00C0102D */  daddu     $v0, $a2, $zero
/* 32FF8 80057BF8 0000282D */  daddu     $a1, $zero, $zero
/* 32FFC 80057BFC 8C830000 */  lw        $v1, ($a0)
/* 33000 80057C00 00021082 */  srl       $v0, $v0, 2
/* 33004 80057C04 AC80000C */  sw        $zero, 0xc($a0)
/* 33008 80057C08 1040000B */  beqz      $v0, .L80057C38
/* 3300C 80057C0C AC830004 */   sw       $v1, 4($a0)
.L80057C10:
/* 33010 80057C10 8C820000 */  lw        $v0, ($a0)
/* 33014 80057C14 00051880 */  sll       $v1, $a1, 2
/* 33018 80057C18 00621821 */  addu      $v1, $v1, $v0
/* 3301C 80057C1C AC600000 */  sw        $zero, ($v1)
/* 33020 80057C20 8C820008 */  lw        $v0, 8($a0)
/* 33024 80057C24 24A50001 */  addiu     $a1, $a1, 1
/* 33028 80057C28 00021082 */  srl       $v0, $v0, 2
/* 3302C 80057C2C 00A2102B */  sltu      $v0, $a1, $v0
/* 33030 80057C30 1440FFF7 */  bnez      $v0, .L80057C10
/* 33034 80057C34 00000000 */   nop
.L80057C38:
/* 33038 80057C38 03E00008 */  jr        $ra
/* 3303C 80057C3C 00000000 */   nop
