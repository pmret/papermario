.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel free_icon
/* DAFF4 801448F4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DAFF8 801448F8 2402F7FF */  addiu     $v0, $zero, -0x801
/* DAFFC 801448FC 00822024 */  and       $a0, $a0, $v0
/* DB000 80144900 AFB10014 */  sw        $s1, 0x14($sp)
/* DB004 80144904 3C118015 */  lui       $s1, 0x8015
/* DB008 80144908 26317960 */  addiu     $s1, $s1, 0x7960
/* DB00C 8014490C AFBF0018 */  sw        $ra, 0x18($sp)
/* DB010 80144910 AFB00010 */  sw        $s0, 0x10($sp)
/* DB014 80144914 8E220000 */  lw        $v0, ($s1)
/* DB018 80144918 00048080 */  sll       $s0, $a0, 2
/* DB01C 8014491C 02021021 */  addu      $v0, $s0, $v0
/* DB020 80144920 8C420000 */  lw        $v0, ($v0)
/* DB024 80144924 8C420000 */  lw        $v0, ($v0)
/* DB028 80144928 3C030001 */  lui       $v1, 1
/* DB02C 8014492C 00431024 */  and       $v0, $v0, $v1
/* DB030 80144930 10400003 */  beqz      $v0, .L80144940
/* DB034 80144934 00000000 */   nop      
/* DB038 80144938 0C051442 */  jal       func_80145108
/* DB03C 8014493C 00000000 */   nop      
.L80144940:
/* DB040 80144940 8E220000 */  lw        $v0, ($s1)
/* DB044 80144944 02021021 */  addu      $v0, $s0, $v0
/* DB048 80144948 0C00AB4B */  jal       heap_free
/* DB04C 8014494C 8C440000 */   lw       $a0, ($v0)
/* DB050 80144950 3C048015 */  lui       $a0, 0x8015
/* DB054 80144954 248412B4 */  addiu     $a0, $a0, 0x12b4
/* DB058 80144958 8E220000 */  lw        $v0, ($s1)
/* DB05C 8014495C 8C830000 */  lw        $v1, ($a0)
/* DB060 80144960 02021021 */  addu      $v0, $s0, $v0
/* DB064 80144964 2463FFFF */  addiu     $v1, $v1, -1
/* DB068 80144968 AC400000 */  sw        $zero, ($v0)
/* DB06C 8014496C AC830000 */  sw        $v1, ($a0)
/* DB070 80144970 8FBF0018 */  lw        $ra, 0x18($sp)
/* DB074 80144974 8FB10014 */  lw        $s1, 0x14($sp)
/* DB078 80144978 8FB00010 */  lw        $s0, 0x10($sp)
/* DB07C 8014497C 03E00008 */  jr        $ra
/* DB080 80144980 27BD0020 */   addiu    $sp, $sp, 0x20
