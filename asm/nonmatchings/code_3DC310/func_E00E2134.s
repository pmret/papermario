.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_E00E2134
/* 3DC444 E00E2134 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 3DC448 E00E2138 AFBF0010 */  sw        $ra, 0x10($sp)
/* 3DC44C E00E213C 8C830000 */  lw        $v1, ($a0)
/* 3DC450 E00E2140 8C85000C */  lw        $a1, 0xc($a0)
/* 3DC454 E00E2144 30620010 */  andi      $v0, $v1, 0x10
/* 3DC458 E00E2148 10400005 */  beqz      $v0, .LE00E2160
/* 3DC45C E00E214C 2402FFEF */   addiu    $v0, $zero, -0x11
/* 3DC460 E00E2150 00621024 */  and       $v0, $v1, $v0
/* 3DC464 E00E2154 AC820000 */  sw        $v0, ($a0)
/* 3DC468 E00E2158 24020010 */  addiu     $v0, $zero, 0x10
/* 3DC46C E00E215C ACA20010 */  sw        $v0, 0x10($a1)
.LE00E2160:
/* 3DC470 E00E2160 8CA30010 */  lw        $v1, 0x10($a1)
/* 3DC474 E00E2164 286203E8 */  slti      $v0, $v1, 0x3e8
/* 3DC478 E00E2168 10400002 */  beqz      $v0, .LE00E2174
/* 3DC47C E00E216C 2462FFFF */   addiu    $v0, $v1, -1
/* 3DC480 E00E2170 ACA20010 */  sw        $v0, 0x10($a1)
.LE00E2174:
/* 3DC484 E00E2174 8CA20014 */  lw        $v0, 0x14($a1)
/* 3DC488 E00E2178 8CA30010 */  lw        $v1, 0x10($a1)
/* 3DC48C E00E217C 24460001 */  addiu     $a2, $v0, 1
/* 3DC490 E00E2180 04610005 */  bgez      $v1, .LE00E2198
/* 3DC494 E00E2184 ACA60014 */   sw       $a2, 0x14($a1)
/* 3DC498 E00E2188 0C080128 */  jal       func_E02004A0
/* 3DC49C E00E218C 00000000 */   nop      
/* 3DC4A0 E00E2190 0803886F */  j         .LE00E21BC
/* 3DC4A4 E00E2194 00000000 */   nop      
.LE00E2198:
/* 3DC4A8 E00E2198 28620010 */  slti      $v0, $v1, 0x10
/* 3DC4AC E00E219C 10400002 */  beqz      $v0, .LE00E21A8
/* 3DC4B0 E00E21A0 00031100 */   sll      $v0, $v1, 4
/* 3DC4B4 E00E21A4 ACA20024 */  sw        $v0, 0x24($a1)
.LE00E21A8:
/* 3DC4B8 E00E21A8 28C20010 */  slti      $v0, $a2, 0x10
/* 3DC4BC E00E21AC 10400003 */  beqz      $v0, .LE00E21BC
/* 3DC4C0 E00E21B0 00061100 */   sll      $v0, $a2, 4
/* 3DC4C4 E00E21B4 2442000F */  addiu     $v0, $v0, 0xf
/* 3DC4C8 E00E21B8 ACA20024 */  sw        $v0, 0x24($a1)
.LE00E21BC:
/* 3DC4CC E00E21BC 8FBF0010 */  lw        $ra, 0x10($sp)
/* 3DC4D0 E00E21C0 03E00008 */  jr        $ra
/* 3DC4D4 E00E21C4 27BD0018 */   addiu    $sp, $sp, 0x18
