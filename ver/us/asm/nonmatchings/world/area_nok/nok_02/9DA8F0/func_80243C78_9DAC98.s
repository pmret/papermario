.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80243C78_9DAC98
/* 9DAC98 80243C78 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 9DAC9C 80243C7C AFBF0010 */  sw        $ra, 0x10($sp)
/* 9DACA0 80243C80 8C82000C */  lw        $v0, 0xc($a0)
/* 9DACA4 80243C84 0C0B1EAF */  jal       evt_get_variable
/* 9DACA8 80243C88 8C450000 */   lw       $a1, ($v0)
/* 9DACAC 80243C8C 0040182D */  daddu     $v1, $v0, $zero
/* 9DACB0 80243C90 10600012 */  beqz      $v1, .L80243CDC
/* 9DACB4 80243C94 0000202D */   daddu    $a0, $zero, $zero
/* 9DACB8 80243C98 8C620000 */  lw        $v0, ($v1)
/* 9DACBC 80243C9C 5040000A */  beql      $v0, $zero, .L80243CC8
/* 9DACC0 80243CA0 00041080 */   sll      $v0, $a0, 2
/* 9DACC4 80243CA4 3C058025 */  lui       $a1, %hi(D_80254BA0)
/* 9DACC8 80243CA8 24A54BA0 */  addiu     $a1, $a1, %lo(D_80254BA0)
.L80243CAC:
/* 9DACCC 80243CAC 24630004 */  addiu     $v1, $v1, 4
/* 9DACD0 80243CB0 24840001 */  addiu     $a0, $a0, 1
/* 9DACD4 80243CB4 ACA20000 */  sw        $v0, ($a1)
/* 9DACD8 80243CB8 8C620000 */  lw        $v0, ($v1)
/* 9DACDC 80243CBC 1440FFFB */  bnez      $v0, .L80243CAC
/* 9DACE0 80243CC0 24A50004 */   addiu    $a1, $a1, 4
/* 9DACE4 80243CC4 00041080 */  sll       $v0, $a0, 2
.L80243CC8:
/* 9DACE8 80243CC8 3C018025 */  lui       $at, %hi(D_80254BA0)
/* 9DACEC 80243CCC 00220821 */  addu      $at, $at, $v0
/* 9DACF0 80243CD0 AC204BA0 */  sw        $zero, %lo(D_80254BA0)($at)
/* 9DACF4 80243CD4 08090F41 */  j         .L80243D04
/* 9DACF8 80243CD8 00000000 */   nop
.L80243CDC:
/* 9DACFC 80243CDC 3C038025 */  lui       $v1, %hi(D_80254BA0)
/* 9DAD00 80243CE0 24634BA0 */  addiu     $v1, $v1, %lo(D_80254BA0)
/* 9DAD04 80243CE4 0060282D */  daddu     $a1, $v1, $zero
.L80243CE8:
/* 9DAD08 80243CE8 24820010 */  addiu     $v0, $a0, 0x10
/* 9DAD0C 80243CEC AC620000 */  sw        $v0, ($v1)
/* 9DAD10 80243CF0 24630004 */  addiu     $v1, $v1, 4
/* 9DAD14 80243CF4 24840001 */  addiu     $a0, $a0, 1
/* 9DAD18 80243CF8 28820070 */  slti      $v0, $a0, 0x70
/* 9DAD1C 80243CFC 1440FFFA */  bnez      $v0, .L80243CE8
/* 9DAD20 80243D00 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80243D04:
/* 9DAD24 80243D04 8FBF0010 */  lw        $ra, 0x10($sp)
/* 9DAD28 80243D08 24020002 */  addiu     $v0, $zero, 2
/* 9DAD2C 80243D0C 03E00008 */  jr        $ra
/* 9DAD30 80243D10 27BD0018 */   addiu    $sp, $sp, 0x18
