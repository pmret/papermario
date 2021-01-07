.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80240E00_8B0E70
/* 8B0E70 80240E00 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 8B0E74 80240E04 AFBF0010 */  sw        $ra, 0x10($sp)
/* 8B0E78 80240E08 8C82000C */  lw        $v0, 0xc($a0)
/* 8B0E7C 80240E0C 0C0B1EAF */  jal       get_variable
/* 8B0E80 80240E10 8C450000 */   lw       $a1, ($v0)
/* 8B0E84 80240E14 0040202D */  daddu     $a0, $v0, $zero
/* 8B0E88 80240E18 3C028025 */  lui       $v0, %hi(D_80257F48)
/* 8B0E8C 80240E1C 8C427F48 */  lw        $v0, %lo(D_80257F48)($v0)
/* 8B0E90 80240E20 24030001 */  addiu     $v1, $zero, 1
/* 8B0E94 80240E24 8C45000C */  lw        $a1, 0xc($v0)
/* 8B0E98 80240E28 1083000D */  beq       $a0, $v1, .L80240E60
/* 8B0E9C 80240E2C 28820002 */   slti     $v0, $a0, 2
/* 8B0EA0 80240E30 10400005 */  beqz      $v0, .L80240E48
/* 8B0EA4 80240E34 24020002 */   addiu    $v0, $zero, 2
/* 8B0EA8 80240E38 10800007 */  beqz      $a0, .L80240E58
/* 8B0EAC 80240E3C 240200C0 */   addiu    $v0, $zero, 0xc0
/* 8B0EB0 80240E40 0809039C */  j         .L80240E70
/* 8B0EB4 80240E44 ACA00038 */   sw       $zero, 0x38($a1)
.L80240E48:
/* 8B0EB8 80240E48 10820008 */  beq       $a0, $v0, .L80240E6C
/* 8B0EBC 80240E4C 24020040 */   addiu    $v0, $zero, 0x40
/* 8B0EC0 80240E50 0809039C */  j         .L80240E70
/* 8B0EC4 80240E54 ACA00038 */   sw       $zero, 0x38($a1)
.L80240E58:
/* 8B0EC8 80240E58 0809039C */  j         .L80240E70
/* 8B0ECC 80240E5C ACA20038 */   sw       $v0, 0x38($a1)
.L80240E60:
/* 8B0ED0 80240E60 24020080 */  addiu     $v0, $zero, 0x80
/* 8B0ED4 80240E64 0809039C */  j         .L80240E70
/* 8B0ED8 80240E68 ACA20038 */   sw       $v0, 0x38($a1)
.L80240E6C:
/* 8B0EDC 80240E6C ACA20038 */  sw        $v0, 0x38($a1)
.L80240E70:
/* 8B0EE0 80240E70 8FBF0010 */  lw        $ra, 0x10($sp)
/* 8B0EE4 80240E74 24020002 */  addiu     $v0, $zero, 2
/* 8B0EE8 80240E78 03E00008 */  jr        $ra
/* 8B0EEC 80240E7C 27BD0018 */   addiu    $sp, $sp, 0x18
