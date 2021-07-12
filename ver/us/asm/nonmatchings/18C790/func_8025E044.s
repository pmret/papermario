.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025E044
/* 18C924 8025E044 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 18C928 8025E048 AFB00010 */  sw        $s0, 0x10($sp)
/* 18C92C 8025E04C 0080802D */  daddu     $s0, $a0, $zero
/* 18C930 8025E050 AFBF0018 */  sw        $ra, 0x18($sp)
/* 18C934 8025E054 AFB10014 */  sw        $s1, 0x14($sp)
/* 18C938 8025E058 8E04009C */  lw        $a0, 0x9c($s0)
/* 18C93C 8025E05C 0C0B5059 */  jal       virtual_entity_get_by_index
/* 18C940 8025E060 3C11FFFF */   lui      $s1, 0xffff
/* 18C944 8025E064 8C440000 */  lw        $a0, ($v0)
/* 18C948 8025E068 0C048B77 */  jal       get_entity_model
/* 18C94C 8025E06C 3631000F */   ori      $s1, $s1, 0xf
/* 18C950 8025E070 0040202D */  daddu     $a0, $v0, $zero
/* 18C954 8025E074 8C820000 */  lw        $v0, ($a0)
/* 18C958 8025E078 00511024 */  and       $v0, $v0, $s1
/* 18C95C 8025E07C 34420008 */  ori       $v0, $v0, 8
/* 18C960 8025E080 AC820000 */  sw        $v0, ($a0)
/* 18C964 8025E084 0C0B5059 */  jal       virtual_entity_get_by_index
/* 18C968 8025E088 8E0400A0 */   lw       $a0, 0xa0($s0)
/* 18C96C 8025E08C 0C048B77 */  jal       get_entity_model
/* 18C970 8025E090 8C440000 */   lw       $a0, ($v0)
/* 18C974 8025E094 0040202D */  daddu     $a0, $v0, $zero
/* 18C978 8025E098 8C820000 */  lw        $v0, ($a0)
/* 18C97C 8025E09C 00511024 */  and       $v0, $v0, $s1
/* 18C980 8025E0A0 34420008 */  ori       $v0, $v0, 8
/* 18C984 8025E0A4 AC820000 */  sw        $v0, ($a0)
/* 18C988 8025E0A8 0C0B5059 */  jal       virtual_entity_get_by_index
/* 18C98C 8025E0AC 8E0400A4 */   lw       $a0, 0xa4($s0)
/* 18C990 8025E0B0 0C048B77 */  jal       get_entity_model
/* 18C994 8025E0B4 8C440000 */   lw       $a0, ($v0)
/* 18C998 8025E0B8 0040202D */  daddu     $a0, $v0, $zero
/* 18C99C 8025E0BC 8C820000 */  lw        $v0, ($a0)
/* 18C9A0 8025E0C0 00511024 */  and       $v0, $v0, $s1
/* 18C9A4 8025E0C4 34420008 */  ori       $v0, $v0, 8
/* 18C9A8 8025E0C8 AC820000 */  sw        $v0, ($a0)
/* 18C9AC 8025E0CC 0C0B5059 */  jal       virtual_entity_get_by_index
/* 18C9B0 8025E0D0 8E0400A8 */   lw       $a0, 0xa8($s0)
/* 18C9B4 8025E0D4 0C048B77 */  jal       get_entity_model
/* 18C9B8 8025E0D8 8C440000 */   lw       $a0, ($v0)
/* 18C9BC 8025E0DC 0040202D */  daddu     $a0, $v0, $zero
/* 18C9C0 8025E0E0 8C830000 */  lw        $v1, ($a0)
/* 18C9C4 8025E0E4 00711824 */  and       $v1, $v1, $s1
/* 18C9C8 8025E0E8 34630008 */  ori       $v1, $v1, 8
/* 18C9CC 8025E0EC AC830000 */  sw        $v1, ($a0)
/* 18C9D0 8025E0F0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 18C9D4 8025E0F4 8FB10014 */  lw        $s1, 0x14($sp)
/* 18C9D8 8025E0F8 8FB00010 */  lw        $s0, 0x10($sp)
/* 18C9DC 8025E0FC 24020002 */  addiu     $v0, $zero, 2
/* 18C9E0 8025E100 03E00008 */  jr        $ra
/* 18C9E4 8025E104 27BD0020 */   addiu    $sp, $sp, 0x20
