.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025D640
/* 18BF20 8025D640 27BDFFD8 */  addiu     $sp, $sp, -0x28
/* 18BF24 8025D644 AFBF0024 */  sw        $ra, 0x24($sp)
/* 18BF28 8025D648 AFB20020 */  sw        $s2, 0x20($sp)
/* 18BF2C 8025D64C AFB1001C */  sw        $s1, 0x1c($sp)
/* 18BF30 8025D650 AFB00018 */  sw        $s0, 0x18($sp)
/* 18BF34 8025D654 8C9000C0 */  lw        $s0, 0xc0($a0)
/* 18BF38 8025D658 00A0882D */  daddu     $s1, $a1, $zero
/* 18BF3C 8025D65C 02119021 */  addu      $s2, $s0, $s1
/* 18BF40 8025D660 824308BC */  lb        $v1, 0x8bc($s2)
/* 18BF44 8025D664 10600005 */  beqz      $v1, .L8025D67C
/* 18BF48 8025D668 24020001 */   addiu    $v0, $zero, 1
/* 18BF4C 8025D66C 10620012 */  beq       $v1, $v0, .L8025D6B8
/* 18BF50 8025D670 00111080 */   sll      $v0, $s1, 2
/* 18BF54 8025D674 080975B9 */  j         .L8025D6E4
/* 18BF58 8025D678 00000000 */   nop      
.L8025D67C:
/* 18BF5C 8025D67C 3C013F80 */  lui       $at, 0x3f80
/* 18BF60 8025D680 44810000 */  mtc1      $at, $f0
/* 18BF64 8025D684 AFA00014 */  sw        $zero, 0x14($sp)
/* 18BF68 8025D688 E7A00010 */  swc1      $f0, 0x10($sp)
/* 18BF6C 8025D68C 8C850058 */  lw        $a1, 0x58($a0)
/* 18BF70 8025D690 8C86005C */  lw        $a2, 0x5c($a0)
/* 18BF74 8025D694 8C870060 */  lw        $a3, 0x60($a0)
/* 18BF78 8025D698 0C01C79C */  jal       func_80071E70
/* 18BF7C 8025D69C 24040001 */   addiu    $a0, $zero, 1
/* 18BF80 8025D6A0 00111880 */  sll       $v1, $s1, 2
/* 18BF84 8025D6A4 02031821 */  addu      $v1, $s0, $v1
/* 18BF88 8025D6A8 AC6208B0 */  sw        $v0, 0x8b0($v1)
/* 18BF8C 8025D6AC 24020001 */  addiu     $v0, $zero, 1
/* 18BF90 8025D6B0 080975B9 */  j         .L8025D6E4
/* 18BF94 8025D6B4 A24208BC */   sb       $v0, 0x8bc($s2)
.L8025D6B8:
/* 18BF98 8025D6B8 02021021 */  addu      $v0, $s0, $v0
/* 18BF9C 8025D6BC 8C4208B0 */  lw        $v0, 0x8b0($v0)
/* 18BFA0 8025D6C0 C4800058 */  lwc1      $f0, 0x58($a0)
/* 18BFA4 8025D6C4 8C43000C */  lw        $v1, 0xc($v0)
/* 18BFA8 8025D6C8 E4600038 */  swc1      $f0, 0x38($v1)
/* 18BFAC 8025D6CC 8C43000C */  lw        $v1, 0xc($v0)
/* 18BFB0 8025D6D0 C480005C */  lwc1      $f0, 0x5c($a0)
/* 18BFB4 8025D6D4 E460003C */  swc1      $f0, 0x3c($v1)
/* 18BFB8 8025D6D8 8C42000C */  lw        $v0, 0xc($v0)
/* 18BFBC 8025D6DC C4800060 */  lwc1      $f0, 0x60($a0)
/* 18BFC0 8025D6E0 E4400040 */  swc1      $f0, 0x40($v0)
.L8025D6E4:
/* 18BFC4 8025D6E4 8FBF0024 */  lw        $ra, 0x24($sp)
/* 18BFC8 8025D6E8 8FB20020 */  lw        $s2, 0x20($sp)
/* 18BFCC 8025D6EC 8FB1001C */  lw        $s1, 0x1c($sp)
/* 18BFD0 8025D6F0 8FB00018 */  lw        $s0, 0x18($sp)
/* 18BFD4 8025D6F4 03E00008 */  jr        $ra
/* 18BFD8 8025D6F8 27BD0028 */   addiu    $sp, $sp, 0x28
