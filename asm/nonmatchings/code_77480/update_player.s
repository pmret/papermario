.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel update_player
/* 78BF0 800DF740 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 78BF4 800DF744 AFBF0018 */  sw        $ra, 0x18($sp)
/* 78BF8 800DF748 AFB10014 */  sw        $s1, 0x14($sp)
/* 78BFC 800DF74C 0C0382CE */  jal       update_partner_timers
/* 78C00 800DF750 AFB00010 */   sw       $s0, 0x10($sp)
/* 78C04 800DF754 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* 78C08 800DF758 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* 78C0C 800DF75C 860200C0 */  lh        $v0, 0xc0($s0)
/* 78C10 800DF760 3C118016 */  lui       $s1, %hi(gCollisionStatus)
/* 78C14 800DF764 2631A550 */  addiu     $s1, $s1, %lo(gCollisionStatus)
/* 78C18 800DF768 28420065 */  slti      $v0, $v0, 0x65
/* 78C1C 800DF76C 10400009 */  beqz      $v0, .L800DF794
/* 78C20 800DF770 00000000 */   nop
/* 78C24 800DF774 C602002C */  lwc1      $f2, 0x2c($s0)
/* 78C28 800DF778 3C01C4FA */  lui       $at, 0xc4fa
/* 78C2C 800DF77C 44810000 */  mtc1      $at, $f0
/* 78C30 800DF780 00000000 */  nop
/* 78C34 800DF784 4600103C */  c.lt.s    $f2, $f0
/* 78C38 800DF788 00000000 */  nop
/* 78C3C 800DF78C 45000039 */  bc1f      .L800DF874
/* 78C40 800DF790 2402FFFF */   addiu    $v0, $zero, -1
.L800DF794:
/* 78C44 800DF794 8E040004 */  lw        $a0, 4($s0)
/* 78C48 800DF798 3C021000 */  lui       $v0, 0x1000
/* 78C4C 800DF79C 00821024 */  and       $v0, $a0, $v0
/* 78C50 800DF7A0 14400034 */  bnez      $v0, .L800DF874
/* 78C54 800DF7A4 2402FFFF */   addiu    $v0, $zero, -1
/* 78C58 800DF7A8 86020016 */  lh        $v0, 0x16($s0)
/* 78C5C 800DF7AC 8603001A */  lh        $v1, 0x1a($s0)
/* 78C60 800DF7B0 44820000 */  mtc1      $v0, $f0
/* 78C64 800DF7B4 00000000 */  nop
/* 78C68 800DF7B8 46800020 */  cvt.s.w   $f0, $f0
/* 78C6C 800DF7BC 86020018 */  lh        $v0, 0x18($s0)
/* 78C70 800DF7C0 A60000C0 */  sh        $zero, 0xc0($s0)
/* 78C74 800DF7C4 E6000028 */  swc1      $f0, 0x28($s0)
/* 78C78 800DF7C8 44820000 */  mtc1      $v0, $f0
/* 78C7C 800DF7CC 00000000 */  nop
/* 78C80 800DF7D0 46800020 */  cvt.s.w   $f0, $f0
/* 78C84 800DF7D4 E600002C */  swc1      $f0, 0x2c($s0)
/* 78C88 800DF7D8 44830000 */  mtc1      $v1, $f0
/* 78C8C 800DF7DC 00000000 */  nop
/* 78C90 800DF7E0 46800020 */  cvt.s.w   $f0, $f0
/* 78C94 800DF7E4 3C020040 */  lui       $v0, 0x40
/* 78C98 800DF7E8 00821024 */  and       $v0, $a0, $v0
/* 78C9C 800DF7EC 1040001E */  beqz      $v0, .L800DF868
/* 78CA0 800DF7F0 E6000030 */   swc1     $f0, 0x30($s0)
/* 78CA4 800DF7F4 3C022000 */  lui       $v0, 0x2000
/* 78CA8 800DF7F8 34420004 */  ori       $v0, $v0, 4
/* 78CAC 800DF7FC 00821025 */  or        $v0, $a0, $v0
/* 78CB0 800DF800 2404FFFC */  addiu     $a0, $zero, -4
/* 78CB4 800DF804 0C00EABB */  jal       get_npc_unsafe
/* 78CB8 800DF808 AE020004 */   sw       $v0, 4($s0)
/* 78CBC 800DF80C 86030016 */  lh        $v1, 0x16($s0)
/* 78CC0 800DF810 44830000 */  mtc1      $v1, $f0
/* 78CC4 800DF814 00000000 */  nop
/* 78CC8 800DF818 46800020 */  cvt.s.w   $f0, $f0
/* 78CCC 800DF81C E4400038 */  swc1      $f0, 0x38($v0)
/* 78CD0 800DF820 86030018 */  lh        $v1, 0x18($s0)
/* 78CD4 800DF824 860400B0 */  lh        $a0, 0xb0($s0)
/* 78CD8 800DF828 00641821 */  addu      $v1, $v1, $a0
/* 78CDC 800DF82C 44830000 */  mtc1      $v1, $f0
/* 78CE0 800DF830 00000000 */  nop
/* 78CE4 800DF834 46800020 */  cvt.s.w   $f0, $f0
/* 78CE8 800DF838 E440003C */  swc1      $f0, 0x3c($v0)
/* 78CEC 800DF83C 8603001A */  lh        $v1, 0x1a($s0)
/* 78CF0 800DF840 44830000 */  mtc1      $v1, $f0
/* 78CF4 800DF844 00000000 */  nop
/* 78CF8 800DF848 46800020 */  cvt.s.w   $f0, $f0
/* 78CFC 800DF84C E4400040 */  swc1      $f0, 0x40($v0)
/* 78D00 800DF850 86030018 */  lh        $v1, 0x18($s0)
/* 78D04 800DF854 44830000 */  mtc1      $v1, $f0
/* 78D08 800DF858 00000000 */  nop
/* 78D0C 800DF85C 46800020 */  cvt.s.w   $f0, $f0
/* 78D10 800DF860 08037E1C */  j         .L800DF870
/* 78D14 800DF864 E4400064 */   swc1     $f0, 0x64($v0)
.L800DF868:
/* 78D18 800DF868 2402000A */  addiu     $v0, $zero, 0xa
/* 78D1C 800DF86C A60200C0 */  sh        $v0, 0xc0($s0)
.L800DF870:
/* 78D20 800DF870 2402FFFF */  addiu     $v0, $zero, -1
.L800DF874:
/* 78D24 800DF874 A6220012 */  sh        $v0, 0x12($s1)
/* 78D28 800DF878 A6220014 */  sh        $v0, 0x14($s1)
/* 78D2C 800DF87C A622000A */  sh        $v0, 0xa($s1)
/* 78D30 800DF880 24020001 */  addiu     $v0, $zero, 1
/* 78D34 800DF884 0C0387E4 */  jal       update_player_input
/* 78D38 800DF888 A6220006 */   sh       $v0, 6($s1)
/* 78D3C 800DF88C 8E020000 */  lw        $v0, ($s0)
/* 78D40 800DF890 2403FBFF */  addiu     $v1, $zero, -0x401
/* 78D44 800DF894 00431024 */  and       $v0, $v0, $v1
/* 78D48 800DF898 0C037FF3 */  jal       func_800DFFCC
/* 78D4C 800DF89C AE020000 */   sw       $v0, ($s0)
/* 78D50 800DF8A0 8E020000 */  lw        $v0, ($s0)
/* 78D54 800DF8A4 30421000 */  andi      $v0, $v0, 0x1000
/* 78D58 800DF8A8 1040000B */  beqz      $v0, .L800DF8D8
/* 78D5C 800DF8AC 24020017 */   addiu    $v0, $zero, 0x17
/* 78D60 800DF8B0 0C03968B */  jal       func_800E5A2C
/* 78D64 800DF8B4 00000000 */   nop
/* 78D68 800DF8B8 0C038082 */  jal       func_800E0208
/* 78D6C 800DF8BC 00000000 */   nop
/* 78D70 800DF8C0 1440000E */  bnez      $v0, .L800DF8FC
/* 78D74 800DF8C4 00000000 */   nop
/* 78D78 800DF8C8 0C038D8F */  jal       collision_main_lateral
/* 78D7C 800DF8CC 00000000 */   nop
/* 78D80 800DF8D0 08037E3F */  j         .L800DF8FC
/* 78D84 800DF8D4 00000000 */   nop
.L800DF8D8:
/* 78D88 800DF8D8 820300B4 */  lb        $v1, 0xb4($s0)
/* 78D8C 800DF8DC 10620005 */  beq       $v1, $v0, .L800DF8F4
/* 78D90 800DF8E0 00000000 */   nop
/* 78D94 800DF8E4 0C037EAB */  jal       func_800DFAAC
/* 78D98 800DF8E8 00000000 */   nop
/* 78D9C 800DF8EC 08037E3F */  j         .L800DF8FC
/* 78DA0 800DF8F0 00000000 */   nop
.L800DF8F4:
/* 78DA4 800DF8F4 0C037EFA */  jal       func_800DFBE8
/* 78DA8 800DF8F8 00000000 */   nop
.L800DF8FC:
/* 78DAC 800DF8FC 8E020000 */  lw        $v0, ($s0)
/* 78DB0 800DF900 30424000 */  andi      $v0, $v0, 0x4000
/* 78DB4 800DF904 1040000B */  beqz      $v0, .L800DF934
/* 78DB8 800DF908 00000000 */   nop
/* 78DBC 800DF90C 96020012 */  lhu       $v0, 0x12($s0)
/* 78DC0 800DF910 2442FFFF */  addiu     $v0, $v0, -1
/* 78DC4 800DF914 A6020012 */  sh        $v0, 0x12($s0)
/* 78DC8 800DF918 00021400 */  sll       $v0, $v0, 0x10
/* 78DCC 800DF91C 1C400005 */  bgtz      $v0, .L800DF934
/* 78DD0 800DF920 2403BFFF */   addiu    $v1, $zero, -0x4001
/* 78DD4 800DF924 8E020000 */  lw        $v0, ($s0)
/* 78DD8 800DF928 A6000012 */  sh        $zero, 0x12($s0)
/* 78DDC 800DF92C 00431024 */  and       $v0, $v0, $v1
/* 78DE0 800DF930 AE020000 */  sw        $v0, ($s0)
.L800DF934:
/* 78DE4 800DF934 8E020004 */  lw        $v0, 4($s0)
/* 78DE8 800DF938 30421000 */  andi      $v0, $v0, 0x1000
/* 78DEC 800DF93C 14400003 */  bnez      $v0, .L800DF94C
/* 78DF0 800DF940 00000000 */   nop
/* 78DF4 800DF944 0C03BF42 */  jal       func_800EFD08
/* 78DF8 800DF948 00000000 */   nop
.L800DF94C:
/* 78DFC 800DF94C 0C0382E4 */  jal       func_800E0B90
/* 78E00 800DF950 00000000 */   nop
/* 78E04 800DF954 3C028007 */  lui       $v0, %hi(gGameStatusPtr)
/* 78E08 800DF958 8C42419C */  lw        $v0, %lo(gGameStatusPtr)($v0)
/* 78E0C 800DF95C C6000028 */  lwc1      $f0, 0x28($s0)
/* 78E10 800DF960 E4400098 */  swc1      $f0, 0x98($v0)
/* 78E14 800DF964 C600002C */  lwc1      $f0, 0x2c($s0)
/* 78E18 800DF968 E440009C */  swc1      $f0, 0x9c($v0)
/* 78E1C 800DF96C C6000030 */  lwc1      $f0, 0x30($s0)
/* 78E20 800DF970 E44000A0 */  swc1      $f0, 0xa0($v0)
/* 78E24 800DF974 C6000084 */  lwc1      $f0, 0x84($s0)
/* 78E28 800DF978 0C039B39 */  jal       check_input_open_menus
/* 78E2C 800DF97C E44000A4 */   swc1     $f0, 0xa4($v0)
/* 78E30 800DF980 8E020004 */  lw        $v0, 4($s0)
/* 78E34 800DF984 30421000 */  andi      $v0, $v0, 0x1000
/* 78E38 800DF988 14400003 */  bnez      $v0, .L800DF998
/* 78E3C 800DF98C 00000000 */   nop
/* 78E40 800DF990 0C039CA3 */  jal       check_input_status_menu
/* 78E44 800DF994 00000000 */   nop
.L800DF998:
/* 78E48 800DF998 0C0386F1 */  jal       update_player_shadow
/* 78E4C 800DF99C 00000000 */   nop
/* 78E50 800DF9A0 0C038206 */  jal       check_for_interactables
/* 78E54 800DF9A4 00000000 */   nop
/* 78E58 800DF9A8 0C038160 */  jal       func_800E0580
/* 78E5C 800DF9AC 00000000 */   nop
/* 78E60 800DF9B0 0C0380E6 */  jal       func_800E0398
/* 78E64 800DF9B4 00000000 */   nop
/* 78E68 800DF9B8 0C0380A5 */  jal       func_800E0294
/* 78E6C 800DF9BC 00000000 */   nop
/* 78E70 800DF9C0 8E020000 */  lw        $v0, ($s0)
/* 78E74 800DF9C4 2403FFEF */  addiu     $v1, $zero, -0x11
/* 78E78 800DF9C8 AE00001C */  sw        $zero, 0x1c($s0)
/* 78E7C 800DF9CC AE000020 */  sw        $zero, 0x20($s0)
/* 78E80 800DF9D0 AE000024 */  sw        $zero, 0x24($s0)
/* 78E84 800DF9D4 00431024 */  and       $v0, $v0, $v1
/* 78E88 800DF9D8 AE020000 */  sw        $v0, ($s0)
/* 78E8C 800DF9DC 8E020004 */  lw        $v0, 4($s0)
/* 78E90 800DF9E0 2403FFF7 */  addiu     $v1, $zero, -9
/* 78E94 800DF9E4 00431024 */  and       $v0, $v0, $v1
/* 78E98 800DF9E8 AE020004 */  sw        $v0, 4($s0)
/* 78E9C 800DF9EC 8FBF0018 */  lw        $ra, 0x18($sp)
/* 78EA0 800DF9F0 8FB10014 */  lw        $s1, 0x14($sp)
/* 78EA4 800DF9F4 8FB00010 */  lw        $s0, 0x10($sp)
/* 78EA8 800DF9F8 03E00008 */  jr        $ra
/* 78EAC 800DF9FC 27BD0020 */   addiu    $sp, $sp, 0x20
