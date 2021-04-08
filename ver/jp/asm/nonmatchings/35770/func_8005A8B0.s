.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_8005A8B0
/* 35CB0 8005A8B0 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* 35CB4 8005A8B4 AFB50024 */  sw        $s5, 0x24($sp)
/* 35CB8 8005A8B8 0080A82D */  daddu     $s5, $a0, $zero
/* 35CBC 8005A8BC AFB60028 */  sw        $s6, 0x28($sp)
/* 35CC0 8005A8C0 00A0B02D */  daddu     $s6, $a1, $zero
/* 35CC4 8005A8C4 AFB7002C */  sw        $s7, 0x2c($sp)
/* 35CC8 8005A8C8 00C0B82D */  daddu     $s7, $a2, $zero
/* 35CCC 8005A8CC 3C028009 */  lui       $v0, %hi(D_800934C0)
/* 35CD0 8005A8D0 244234C0 */  addiu     $v0, $v0, %lo(D_800934C0)
/* 35CD4 8005A8D4 AFBF0030 */  sw        $ra, 0x30($sp)
/* 35CD8 8005A8D8 AFB40020 */  sw        $s4, 0x20($sp)
/* 35CDC 8005A8DC AFB3001C */  sw        $s3, 0x1c($sp)
/* 35CE0 8005A8E0 AFB20018 */  sw        $s2, 0x18($sp)
/* 35CE4 8005A8E4 AFB10014 */  sw        $s1, 0x14($sp)
/* 35CE8 8005A8E8 AFB00010 */  sw        $s0, 0x10($sp)
/* 35CEC 8005A8EC 8C440004 */  lw        $a0, 4($v0)
/* 35CF0 8005A8F0 1080001F */  beqz      $a0, .L8005A970
/* 35CF4 8005A8F4 0000A02D */   daddu    $s4, $zero, $zero
/* 35CF8 8005A8F8 0280902D */  daddu     $s2, $s4, $zero
.L8005A8FC:
/* 35CFC 8005A8FC 02421021 */  addu      $v0, $s2, $v0
/* 35D00 8005A900 8C420000 */  lw        $v0, ($v0)
/* 35D04 8005A904 18400012 */  blez      $v0, .L8005A950
/* 35D08 8005A908 0000802D */   daddu    $s0, $zero, $zero
/* 35D0C 8005A90C 3C028009 */  lui       $v0, %hi(D_800934C0)
/* 35D10 8005A910 244234C0 */  addiu     $v0, $v0, %lo(D_800934C0)
/* 35D14 8005A914 02429821 */  addu      $s3, $s2, $v0
/* 35D18 8005A918 0080882D */  daddu     $s1, $a0, $zero
.L8005A91C:
/* 35D1C 8005A91C 8E240000 */  lw        $a0, ($s1)
/* 35D20 8005A920 0C01BB54 */  jal       func_8006ED50
/* 35D24 8005A924 02A0282D */   daddu    $a1, $s5, $zero
/* 35D28 8005A928 54400005 */  bnel      $v0, $zero, .L8005A940
/* 35D2C 8005A92C 26100001 */   addiu    $s0, $s0, 1
/* 35D30 8005A930 24020001 */  addiu     $v0, $zero, 1
/* 35D34 8005A934 A6D40000 */  sh        $s4, ($s6)
/* 35D38 8005A938 08016A5D */  j         .L8005A974
/* 35D3C 8005A93C A6F00000 */   sh       $s0, ($s7)
.L8005A940:
/* 35D40 8005A940 8E620000 */  lw        $v0, ($s3)
/* 35D44 8005A944 0202102A */  slt       $v0, $s0, $v0
/* 35D48 8005A948 1440FFF4 */  bnez      $v0, .L8005A91C
/* 35D4C 8005A94C 26310020 */   addiu    $s1, $s1, 0x20
.L8005A950:
/* 35D50 8005A950 26520010 */  addiu     $s2, $s2, 0x10
/* 35D54 8005A954 3C048009 */  lui       $a0, %hi(D_800934C4)
/* 35D58 8005A958 00922021 */  addu      $a0, $a0, $s2
/* 35D5C 8005A95C 8C8434C4 */  lw        $a0, %lo(D_800934C4)($a0)
/* 35D60 8005A960 3C028009 */  lui       $v0, %hi(D_800934C0)
/* 35D64 8005A964 244234C0 */  addiu     $v0, $v0, %lo(D_800934C0)
/* 35D68 8005A968 1480FFE4 */  bnez      $a0, .L8005A8FC
/* 35D6C 8005A96C 26940001 */   addiu    $s4, $s4, 1
.L8005A970:
/* 35D70 8005A970 0000102D */  daddu     $v0, $zero, $zero
.L8005A974:
/* 35D74 8005A974 8FBF0030 */  lw        $ra, 0x30($sp)
/* 35D78 8005A978 8FB7002C */  lw        $s7, 0x2c($sp)
/* 35D7C 8005A97C 8FB60028 */  lw        $s6, 0x28($sp)
/* 35D80 8005A980 8FB50024 */  lw        $s5, 0x24($sp)
/* 35D84 8005A984 8FB40020 */  lw        $s4, 0x20($sp)
/* 35D88 8005A988 8FB3001C */  lw        $s3, 0x1c($sp)
/* 35D8C 8005A98C 8FB20018 */  lw        $s2, 0x18($sp)
/* 35D90 8005A990 8FB10014 */  lw        $s1, 0x14($sp)
/* 35D94 8005A994 8FB00010 */  lw        $s0, 0x10($sp)
/* 35D98 8005A998 03E00008 */  jr        $ra
/* 35D9C 8005A99C 27BD0038 */   addiu    $sp, $sp, 0x38
