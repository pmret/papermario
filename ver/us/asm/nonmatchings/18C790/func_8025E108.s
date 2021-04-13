.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025E108
/* 18C9E8 8025E108 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18C9EC 8025E10C AFBF0010 */  sw        $ra, 0x10($sp)
/* 18C9F0 8025E110 0C0B5059 */  jal       func_802D4164
/* 18C9F4 8025E114 8C8400A8 */   lw       $a0, 0xa8($a0)
/* 18C9F8 8025E118 0C048B77 */  jal       get_entity_model
/* 18C9FC 8025E11C 8C440000 */   lw       $a0, ($v0)
/* 18CA00 8025E120 3C05FFFF */  lui       $a1, 0xffff
/* 18CA04 8025E124 0040202D */  daddu     $a0, $v0, $zero
/* 18CA08 8025E128 8C830000 */  lw        $v1, ($a0)
/* 18CA0C 8025E12C 34A5000F */  ori       $a1, $a1, 0xf
/* 18CA10 8025E130 00651824 */  and       $v1, $v1, $a1
/* 18CA14 8025E134 34630008 */  ori       $v1, $v1, 8
/* 18CA18 8025E138 AC830000 */  sw        $v1, ($a0)
/* 18CA1C 8025E13C 8FBF0010 */  lw        $ra, 0x10($sp)
/* 18CA20 8025E140 24020002 */  addiu     $v0, $zero, 2
/* 18CA24 8025E144 03E00008 */  jr        $ra
/* 18CA28 8025E148 27BD0018 */   addiu    $sp, $sp, 0x18
