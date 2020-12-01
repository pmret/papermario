.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242B0C_825DCC
/* 825DCC 80242B0C 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 825DD0 80242B10 AFBF0010 */  sw        $ra, 0x10($sp)
/* 825DD4 80242B14 8C82000C */  lw        $v0, 0xc($a0)
/* 825DD8 80242B18 0C0B1EAF */  jal       get_variable
/* 825DDC 80242B1C 8C450000 */   lw       $a1, ($v0)
/* 825DE0 80242B20 0040182D */  daddu     $v1, $v0, $zero
/* 825DE4 80242B24 10600012 */  beqz      $v1, .L80242B70
/* 825DE8 80242B28 0000202D */   daddu    $a0, $zero, $zero
/* 825DEC 80242B2C 8C620000 */  lw        $v0, ($v1)
/* 825DF0 80242B30 5040000A */  beql      $v0, $zero, .L80242B5C
/* 825DF4 80242B34 00041080 */   sll      $v0, $a0, 2
/* 825DF8 80242B38 3C058025 */  lui       $a1, %hi(D_8024E570)
/* 825DFC 80242B3C 24A5E570 */  addiu     $a1, $a1, %lo(D_8024E570)
.L80242B40:
/* 825E00 80242B40 24630004 */  addiu     $v1, $v1, 4
/* 825E04 80242B44 24840001 */  addiu     $a0, $a0, 1
/* 825E08 80242B48 ACA20000 */  sw        $v0, ($a1)
/* 825E0C 80242B4C 8C620000 */  lw        $v0, ($v1)
/* 825E10 80242B50 1440FFFB */  bnez      $v0, .L80242B40
/* 825E14 80242B54 24A50004 */   addiu    $a1, $a1, 4
/* 825E18 80242B58 00041080 */  sll       $v0, $a0, 2
.L80242B5C:
/* 825E1C 80242B5C 3C018025 */  lui       $at, %hi(D_8024E570)
/* 825E20 80242B60 00220821 */  addu      $at, $at, $v0
/* 825E24 80242B64 AC20E570 */  sw        $zero, %lo(D_8024E570)($at)
/* 825E28 80242B68 08090AE6 */  j         .L80242B98
/* 825E2C 80242B6C 00000000 */   nop      
.L80242B70:
/* 825E30 80242B70 3C038025 */  lui       $v1, %hi(D_8024E570)
/* 825E34 80242B74 2463E570 */  addiu     $v1, $v1, %lo(D_8024E570)
/* 825E38 80242B78 0060282D */  daddu     $a1, $v1, $zero
.L80242B7C:
/* 825E3C 80242B7C 24820010 */  addiu     $v0, $a0, 0x10
/* 825E40 80242B80 AC620000 */  sw        $v0, ($v1)
/* 825E44 80242B84 24630004 */  addiu     $v1, $v1, 4
/* 825E48 80242B88 24840001 */  addiu     $a0, $a0, 1
/* 825E4C 80242B8C 28820070 */  slti      $v0, $a0, 0x70
/* 825E50 80242B90 1440FFFA */  bnez      $v0, .L80242B7C
/* 825E54 80242B94 ACA001C0 */   sw       $zero, 0x1c0($a1)
.L80242B98:
/* 825E58 80242B98 8FBF0010 */  lw        $ra, 0x10($sp)
/* 825E5C 80242B9C 24020002 */  addiu     $v0, $zero, 2
/* 825E60 80242BA0 03E00008 */  jr        $ra
/* 825E64 80242BA4 27BD0018 */   addiu    $sp, $sp, 0x18
