.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80242F14_A1E014
/* A1E014 80242F14 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* A1E018 80242F18 AFBF0010 */  sw        $ra, 0x10($sp)
/* A1E01C 80242F1C 8C82000C */  lw        $v0, 0xc($a0)
/* A1E020 80242F20 0C0B1EAF */  jal       get_variable
/* A1E024 80242F24 8C450000 */   lw       $a1, ($v0)
/* A1E028 80242F28 0040202D */  daddu     $a0, $v0, $zero
/* A1E02C 80242F2C 3C028025 */  lui       $v0, 0x8025
/* A1E030 80242F30 8C42BDF0 */  lw        $v0, -0x4210($v0)
/* A1E034 80242F34 24030001 */  addiu     $v1, $zero, 1
/* A1E038 80242F38 8C45000C */  lw        $a1, 0xc($v0)
/* A1E03C 80242F3C 1083000D */  beq       $a0, $v1, .L80242F74
/* A1E040 80242F40 28820002 */   slti     $v0, $a0, 2
/* A1E044 80242F44 10400005 */  beqz      $v0, .L80242F5C
/* A1E048 80242F48 24020002 */   addiu    $v0, $zero, 2
/* A1E04C 80242F4C 10800007 */  beqz      $a0, .L80242F6C
/* A1E050 80242F50 240200C0 */   addiu    $v0, $zero, 0xc0
/* A1E054 80242F54 08090BE1 */  j         .L80242F84
/* A1E058 80242F58 ACA00038 */   sw       $zero, 0x38($a1)
.L80242F5C:
/* A1E05C 80242F5C 10820008 */  beq       $a0, $v0, .L80242F80
/* A1E060 80242F60 24020040 */   addiu    $v0, $zero, 0x40
/* A1E064 80242F64 08090BE1 */  j         .L80242F84
/* A1E068 80242F68 ACA00038 */   sw       $zero, 0x38($a1)
.L80242F6C:
/* A1E06C 80242F6C 08090BE1 */  j         .L80242F84
/* A1E070 80242F70 ACA20038 */   sw       $v0, 0x38($a1)
.L80242F74:
/* A1E074 80242F74 24020080 */  addiu     $v0, $zero, 0x80
/* A1E078 80242F78 08090BE1 */  j         .L80242F84
/* A1E07C 80242F7C ACA20038 */   sw       $v0, 0x38($a1)
.L80242F80:
/* A1E080 80242F80 ACA20038 */  sw        $v0, 0x38($a1)
.L80242F84:
/* A1E084 80242F84 8FBF0010 */  lw        $ra, 0x10($sp)
/* A1E088 80242F88 24020002 */  addiu     $v0, $zero, 2
/* A1E08C 80242F8C 03E00008 */  jr        $ra
/* A1E090 80242F90 27BD0018 */   addiu    $sp, $sp, 0x18
