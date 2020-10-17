.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel set_ui_panel_properties
/* DE3C8 80147CC8 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* DE3CC 80147CCC 0080582D */  daddu     $t3, $a0, $zero
/* DE3D0 80147CD0 3C0A8016 */  lui       $t2, %hi(D_80159D50)
/* DE3D4 80147CD4 254A9D50 */  addiu     $t2, $t2, %lo(D_80159D50)
/* DE3D8 80147CD8 8FA90030 */  lw        $t1, 0x30($sp)
/* DE3DC 80147CDC 000B1140 */  sll       $v0, $t3, 5
/* DE3E0 80147CE0 AFB00010 */  sw        $s0, 0x10($sp)
/* DE3E4 80147CE4 004A8021 */  addu      $s0, $v0, $t2
/* DE3E8 80147CE8 AFB10014 */  sw        $s1, 0x14($sp)
/* DE3EC 80147CEC 8FB10034 */  lw        $s1, 0x34($sp)
/* DE3F0 80147CF0 8FA40038 */  lw        $a0, 0x38($sp)
/* DE3F4 80147CF4 8FA8003C */  lw        $t0, 0x3c($sp)
/* DE3F8 80147CF8 8FA30040 */  lw        $v1, 0x40($sp)
/* DE3FC 80147CFC 24020005 */  addiu     $v0, $zero, 5
/* DE400 80147D00 AFBF0018 */  sw        $ra, 0x18($sp)
/* DE404 80147D04 A2020000 */  sb        $v0, ($s0)
/* DE408 80147D08 A605000C */  sh        $a1, 0xc($s0)
/* DE40C 80147D0C A606000E */  sh        $a2, 0xe($s0)
/* DE410 80147D10 A6070010 */  sh        $a3, 0x10($s0)
/* DE414 80147D14 AE000004 */  sw        $zero, 4($s0)
/* DE418 80147D18 0220282D */  daddu     $a1, $s1, $zero
/* DE41C 80147D1C A2030003 */  sb        $v1, 3($s0)
/* DE420 80147D20 00031E00 */  sll       $v1, $v1, 0x18
/* DE424 80147D24 00031E03 */  sra       $v1, $v1, 0x18
/* DE428 80147D28 A6090012 */  sh        $t1, 0x12($s0)
/* DE42C 80147D2C AE040014 */  sw        $a0, 0x14($s0)
/* DE430 80147D30 04600006 */  bltz      $v1, .L80147D4C
/* DE434 80147D34 AE080018 */   sw       $t0, 0x18($s0)
/* DE438 80147D38 00031940 */  sll       $v1, $v1, 5
/* DE43C 80147D3C 006A1821 */  addu      $v1, $v1, $t2
/* DE440 80147D40 90620000 */  lbu       $v0, ($v1)
/* DE444 80147D44 34420010 */  ori       $v0, $v0, 0x10
/* DE448 80147D48 A0620000 */  sb        $v0, ($v1)
.L80147D4C:
/* DE44C 80147D4C 0160202D */  daddu     $a0, $t3, $zero
/* DE450 80147D50 0C051F5C */  jal       func_80147D70
/* DE454 80147D54 30A500FF */   andi     $a1, $a1, 0xff
/* DE458 80147D58 A2110002 */  sb        $s1, 2($s0)
/* DE45C 80147D5C 8FBF0018 */  lw        $ra, 0x18($sp)
/* DE460 80147D60 8FB10014 */  lw        $s1, 0x14($sp)
/* DE464 80147D64 8FB00010 */  lw        $s0, 0x10($sp)
/* DE468 80147D68 03E00008 */  jr        $ra
/* DE46C 80147D6C 27BD0020 */   addiu    $sp, $sp, 0x20
