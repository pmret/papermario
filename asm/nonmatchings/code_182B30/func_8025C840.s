.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8025C840
/* 18B120 8025C840 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 18B124 8025C844 AFBF0010 */  sw        $ra, 0x10($sp)
/* 18B128 8025C848 8CA20000 */  lw        $v0, ($a1)
/* 18B12C 8025C84C 30420002 */  andi      $v0, $v0, 2
/* 18B130 8025C850 14400010 */  bnez      $v0, .L8025C894
/* 18B134 8025C854 0000102D */   daddu    $v0, $zero, $zero
/* 18B138 8025C858 8CA200C0 */  lw        $v0, 0xc0($a1)
/* 18B13C 8025C85C 80430750 */  lb        $v1, 0x750($v0)
/* 18B140 8025C860 10600005 */  beqz      $v1, .L8025C878
/* 18B144 8025C864 2402000B */   addiu    $v0, $zero, 0xb
/* 18B148 8025C868 10620007 */  beq       $v1, $v0, .L8025C888
/* 18B14C 8025C86C 0000102D */   daddu    $v0, $zero, $zero
/* 18B150 8025C870 08097225 */  j         .L8025C894
/* 18B154 8025C874 00000000 */   nop      
.L8025C878:
/* 18B158 8025C878 0C097228 */  jal       func_8025C8A0
/* 18B15C 8025C87C 00000000 */   nop      
/* 18B160 8025C880 08097225 */  j         .L8025C894
/* 18B164 8025C884 0000102D */   daddu    $v0, $zero, $zero
.L8025C888:
/* 18B168 8025C888 0C097246 */  jal       func_8025C918
/* 18B16C 8025C88C 00000000 */   nop      
/* 18B170 8025C890 0000102D */  daddu     $v0, $zero, $zero
.L8025C894:
/* 18B174 8025C894 8FBF0010 */  lw        $ra, 0x10($sp)
/* 18B178 8025C898 03E00008 */  jr        $ra
/* 18B17C 8025C89C 27BD0018 */   addiu    $sp, $sp, 0x18
