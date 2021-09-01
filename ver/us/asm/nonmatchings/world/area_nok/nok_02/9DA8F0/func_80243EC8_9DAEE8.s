.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243EC8_9DAEE8
/* 9DAEE8 80243EC8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DAEEC 80243ECC AFB00010 */  sw        $s0, 0x10($sp)
/* 9DAEF0 80243ED0 0080802D */  daddu     $s0, $a0, $zero
/* 9DAEF4 80243ED4 AFBF0014 */  sw        $ra, 0x14($sp)
/* 9DAEF8 80243ED8 8E02000C */  lw        $v0, 0xc($s0)
/* 9DAEFC 80243EDC 0C0B1EAF */  jal       evt_get_variable
/* 9DAF00 80243EE0 8C450000 */   lw       $a1, ($v0)
/* 9DAF04 80243EE4 30420003 */  andi      $v0, $v0, 3
/* 9DAF08 80243EE8 10400003 */  beqz      $v0, .L80243EF8
/* 9DAF0C 80243EEC 24020001 */   addiu    $v0, $zero, 1
/* 9DAF10 80243EF0 08090FBF */  j         .L80243EFC
/* 9DAF14 80243EF4 AE000084 */   sw       $zero, 0x84($s0)
.L80243EF8:
/* 9DAF18 80243EF8 AE020084 */  sw        $v0, 0x84($s0)
.L80243EFC:
/* 9DAF1C 80243EFC 8FBF0014 */  lw        $ra, 0x14($sp)
/* 9DAF20 80243F00 8FB00010 */  lw        $s0, 0x10($sp)
/* 9DAF24 80243F04 24020002 */  addiu     $v0, $zero, 2
/* 9DAF28 80243F08 03E00008 */  jr        $ra
/* 9DAF2C 80243F0C 27BD0018 */   addiu    $sp, $sp, 0x18
