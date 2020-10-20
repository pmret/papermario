.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80241884
/* CF93F4 80241884 27BDFFB8 */  addiu     $sp, $sp, -0x48
/* CF93F8 80241888 AFB1001C */  sw        $s1, 0x1c($sp)
/* CF93FC 8024188C 0080882D */  daddu     $s1, $a0, $zero
/* CF9400 80241890 AFBF0034 */  sw        $ra, 0x34($sp)
/* CF9404 80241894 AFB60030 */  sw        $s6, 0x30($sp)
/* CF9408 80241898 AFB5002C */  sw        $s5, 0x2c($sp)
/* CF940C 8024189C AFB40028 */  sw        $s4, 0x28($sp)
/* CF9410 802418A0 AFB30024 */  sw        $s3, 0x24($sp)
/* CF9414 802418A4 AFB20020 */  sw        $s2, 0x20($sp)
/* CF9418 802418A8 AFB00018 */  sw        $s0, 0x18($sp)
/* CF941C 802418AC F7B60040 */  sdc1      $f22, 0x40($sp)
/* CF9420 802418B0 F7B40038 */  sdc1      $f20, 0x38($sp)
/* CF9424 802418B4 8E30000C */  lw        $s0, 0xc($s1)
/* CF9428 802418B8 8E160000 */  lw        $s6, ($s0)
/* CF942C 802418BC 26100004 */  addiu     $s0, $s0, 4
/* CF9430 802418C0 0C0B1EAF */  jal       get_variable
/* CF9434 802418C4 02C0282D */   daddu    $a1, $s6, $zero
/* CF9438 802418C8 44820000 */  mtc1      $v0, $f0
/* CF943C 802418CC 00000000 */  nop       
/* CF9440 802418D0 46800020 */  cvt.s.w   $f0, $f0
/* CF9444 802418D4 E7A00010 */  swc1      $f0, 0x10($sp)
/* CF9448 802418D8 8E140000 */  lw        $s4, ($s0)
/* CF944C 802418DC 26100004 */  addiu     $s0, $s0, 4
/* CF9450 802418E0 0220202D */  daddu     $a0, $s1, $zero
/* CF9454 802418E4 0C0B1EAF */  jal       get_variable
/* CF9458 802418E8 0280282D */   daddu    $a1, $s4, $zero
/* CF945C 802418EC 0220202D */  daddu     $a0, $s1, $zero
/* CF9460 802418F0 8E150000 */  lw        $s5, ($s0)
/* CF9464 802418F4 4482B000 */  mtc1      $v0, $f22
/* CF9468 802418F8 00000000 */  nop       
/* CF946C 802418FC 4680B5A0 */  cvt.s.w   $f22, $f22
/* CF9470 80241900 0C0B1EAF */  jal       get_variable
/* CF9474 80241904 02A0282D */   daddu    $a1, $s5, $zero
/* CF9478 80241908 2404FFFC */  addiu     $a0, $zero, -4
/* CF947C 8024190C 44820000 */  mtc1      $v0, $f0
/* CF9480 80241910 00000000 */  nop       
/* CF9484 80241914 46800020 */  cvt.s.w   $f0, $f0
/* CF9488 80241918 0C00EABB */  jal       get_npc_unsafe
/* CF948C 8024191C E7A00014 */   swc1     $f0, 0x14($sp)
/* CF9490 80241920 3C048007 */  lui       $a0, %hi(gCurrentCameraID)
/* CF9494 80241924 8C847410 */  lw        $a0, %lo(gCurrentCameraID)($a0)
/* CF9498 80241928 3C014334 */  lui       $at, 0x4334
/* CF949C 8024192C 44816000 */  mtc1      $at, $f12
/* CF94A0 80241930 00041880 */  sll       $v1, $a0, 2
/* CF94A4 80241934 00641821 */  addu      $v1, $v1, $a0
/* CF94A8 80241938 00031880 */  sll       $v1, $v1, 2
/* CF94AC 8024193C 00641823 */  subu      $v1, $v1, $a0
/* CF94B0 80241940 000320C0 */  sll       $a0, $v1, 3
/* CF94B4 80241944 00641821 */  addu      $v1, $v1, $a0
/* CF94B8 80241948 000318C0 */  sll       $v1, $v1, 3
/* CF94BC 8024194C 3C01800B */  lui       $at, 0x800b
/* CF94C0 80241950 00230821 */  addu      $at, $at, $v1
/* CF94C4 80241954 C4201DEC */  lwc1      $f0, 0x1dec($at)
/* CF94C8 80241958 460C0300 */  add.s     $f12, $f0, $f12
/* CF94CC 8024195C 0C00A6C9 */  jal       clamp_angle
/* CF94D0 80241960 0040982D */   daddu    $s3, $v0, $zero
/* CF94D4 80241964 27B00010 */  addiu     $s0, $sp, 0x10
/* CF94D8 80241968 0200202D */  daddu     $a0, $s0, $zero
/* CF94DC 8024196C 27B20014 */  addiu     $s2, $sp, 0x14
/* CF94E0 80241970 0240282D */  daddu     $a1, $s2, $zero
/* CF94E4 80241974 3C064170 */  lui       $a2, 0x4170
/* CF94E8 80241978 8E67000C */  lw        $a3, 0xc($s3)
/* CF94EC 8024197C 0C00A7E7 */  jal       add_vec2D_polar
/* CF94F0 80241980 46000506 */   mov.s    $f20, $f0
/* CF94F4 80241984 0200202D */  daddu     $a0, $s0, $zero
/* CF94F8 80241988 3C064120 */  lui       $a2, 0x4120
/* CF94FC 8024198C 4407A000 */  mfc1      $a3, $f20
/* CF9500 80241990 0C00A7E7 */  jal       add_vec2D_polar
/* CF9504 80241994 0240282D */   daddu    $a1, $s2, $zero
/* CF9508 80241998 0220202D */  daddu     $a0, $s1, $zero
/* CF950C 8024199C C7A00010 */  lwc1      $f0, 0x10($sp)
/* CF9510 802419A0 4600008D */  trunc.w.s $f2, $f0
/* CF9514 802419A4 44061000 */  mfc1      $a2, $f2
/* CF9518 802419A8 0C0B2026 */  jal       set_variable
/* CF951C 802419AC 02C0282D */   daddu    $a1, $s6, $zero
/* CF9520 802419B0 0220202D */  daddu     $a0, $s1, $zero
/* CF9524 802419B4 4600B08D */  trunc.w.s $f2, $f22
/* CF9528 802419B8 44061000 */  mfc1      $a2, $f2
/* CF952C 802419BC 0C0B2026 */  jal       set_variable
/* CF9530 802419C0 0280282D */   daddu    $a1, $s4, $zero
/* CF9534 802419C4 0220202D */  daddu     $a0, $s1, $zero
/* CF9538 802419C8 C7A00014 */  lwc1      $f0, 0x14($sp)
/* CF953C 802419CC 4600008D */  trunc.w.s $f2, $f0
/* CF9540 802419D0 44061000 */  mfc1      $a2, $f2
/* CF9544 802419D4 0C0B2026 */  jal       set_variable
/* CF9548 802419D8 02A0282D */   daddu    $a1, $s5, $zero
/* CF954C 802419DC 8FBF0034 */  lw        $ra, 0x34($sp)
/* CF9550 802419E0 8FB60030 */  lw        $s6, 0x30($sp)
/* CF9554 802419E4 8FB5002C */  lw        $s5, 0x2c($sp)
/* CF9558 802419E8 8FB40028 */  lw        $s4, 0x28($sp)
/* CF955C 802419EC 8FB30024 */  lw        $s3, 0x24($sp)
/* CF9560 802419F0 8FB20020 */  lw        $s2, 0x20($sp)
/* CF9564 802419F4 8FB1001C */  lw        $s1, 0x1c($sp)
/* CF9568 802419F8 8FB00018 */  lw        $s0, 0x18($sp)
/* CF956C 802419FC D7B60040 */  ldc1      $f22, 0x40($sp)
/* CF9570 80241A00 D7B40038 */  ldc1      $f20, 0x38($sp)
/* CF9574 80241A04 24020002 */  addiu     $v0, $zero, 2
/* CF9578 80241A08 03E00008 */  jr        $ra
/* CF957C 80241A0C 27BD0048 */   addiu    $sp, $sp, 0x48
