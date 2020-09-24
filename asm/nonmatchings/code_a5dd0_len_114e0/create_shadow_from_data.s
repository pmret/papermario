.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel create_shadow_from_data
/* A82D8 80111BD8 27BDFFC8 */  addiu     $sp, $sp, -0x38
/* A82DC 80111BDC F7B40020 */  sdc1      $f20, 0x20($sp)
/* A82E0 80111BE0 4485A000 */  mtc1      $a1, $f20
/* A82E4 80111BE4 F7B60028 */  sdc1      $f22, 0x28($sp)
/* A82E8 80111BE8 4486B000 */  mtc1      $a2, $f22
/* A82EC 80111BEC F7B80030 */  sdc1      $f24, 0x30($sp)
/* A82F0 80111BF0 4487C000 */  mtc1      $a3, $f24
/* A82F4 80111BF4 3C038015 */  lui       $v1, 0x8015
/* A82F8 80111BF8 8C631658 */  lw        $v1, 0x1658($v1)
/* A82FC 80111BFC AFB20018 */  sw        $s2, 0x18($sp)
/* A8300 80111C00 0080902D */  daddu     $s2, $a0, $zero
/* A8304 80111C04 AFB10014 */  sw        $s1, 0x14($sp)
/* A8308 80111C08 0000882D */  daddu     $s1, $zero, $zero
/* A830C 80111C0C AFBF001C */  sw        $ra, 0x1c($sp)
/* A8310 80111C10 AFB00010 */  sw        $s0, 0x10($sp)
.L80111C14:
/* A8314 80111C14 8C620000 */  lw        $v0, ($v1)
/* A8318 80111C18 10400006 */  beqz      $v0, .L80111C34
/* A831C 80111C1C 2A22003C */   slti     $v0, $s1, 0x3c
/* A8320 80111C20 26310001 */  addiu     $s1, $s1, 1
/* A8324 80111C24 2A22003C */  slti      $v0, $s1, 0x3c
/* A8328 80111C28 1440FFFA */  bnez      $v0, .L80111C14
/* A832C 80111C2C 24630004 */   addiu    $v1, $v1, 4
/* A8330 80111C30 2A22003C */  slti      $v0, $s1, 0x3c
.L80111C34:
/* A8334 80111C34 14400003 */  bnez      $v0, .L80111C44
/* A8338 80111C38 00000000 */   nop      
.L80111C3C:
/* A833C 80111C3C 0804470F */  j         .L80111C3C
/* A8340 80111C40 00000000 */   nop      
.L80111C44:
/* A8344 80111C44 0C00AB39 */  jal       heap_malloc
/* A8348 80111C48 24040078 */   addiu    $a0, $zero, 0x78
/* A834C 80111C4C 0040802D */  daddu     $s0, $v0, $zero
/* A8350 80111C50 0200202D */  daddu     $a0, $s0, $zero
/* A8354 80111C54 24050078 */  addiu     $a1, $zero, 0x78
/* A8358 80111C58 3C038015 */  lui       $v1, 0x8015
/* A835C 80111C5C 8C631658 */  lw        $v1, 0x1658($v1)
/* A8360 80111C60 00111080 */  sll       $v0, $s1, 2
/* A8364 80111C64 00431021 */  addu      $v0, $v0, $v1
/* A8368 80111C68 0C00A580 */  jal       mem_clear
/* A836C 80111C6C AC500000 */   sw       $s0, ($v0)
/* A8370 80111C70 A2110004 */  sb        $s1, 4($s0)
/* A8374 80111C74 96430000 */  lhu       $v1, ($s2)
/* A8378 80111C78 3C013F80 */  lui       $at, 0x3f80
/* A837C 80111C7C 44810000 */  mtc1      $at, $f0
/* A8380 80111C80 24020080 */  addiu     $v0, $zero, 0x80
/* A8384 80111C84 A2020005 */  sb        $v0, 5($s0)
/* A8388 80111C88 A2020006 */  sb        $v0, 6($s0)
/* A838C 80111C8C 3C028000 */  lui       $v0, 0x8000
/* A8390 80111C90 E6140010 */  swc1      $f20, 0x10($s0)
/* A8394 80111C94 E6160014 */  swc1      $f22, 0x14($s0)
/* A8398 80111C98 E6180018 */  swc1      $f24, 0x18($s0)
/* A839C 80111C9C 00621825 */  or        $v1, $v1, $v0
/* A83A0 80111CA0 AE030000 */  sw        $v1, ($s0)
/* A83A4 80111CA4 E600001C */  swc1      $f0, 0x1c($s0)
/* A83A8 80111CA8 E6000020 */  swc1      $f0, 0x20($s0)
/* A83AC 80111CAC E6000024 */  swc1      $f0, 0x24($s0)
/* A83B0 80111CB0 8E420008 */  lw        $v0, 8($s2)
/* A83B4 80111CB4 1040000C */  beqz      $v0, .L80111CE8
/* A83B8 80111CB8 0060102D */   daddu    $v0, $v1, $zero
/* A83BC 80111CBC 34420008 */  ori       $v0, $v0, 8
/* A83C0 80111CC0 AE020000 */  sw        $v0, ($s0)
/* A83C4 80111CC4 0C04792E */  jal       func_8011E4B8
/* A83C8 80111CC8 8E440004 */   lw       $a0, 4($s2)
/* A83CC 80111CCC A6020008 */  sh        $v0, 8($s0)
/* A83D0 80111CD0 00021400 */  sll       $v0, $v0, 0x10
/* A83D4 80111CD4 8E450008 */  lw        $a1, 8($s2)
/* A83D8 80111CD8 0C0480EB */  jal       func_801203AC
/* A83DC 80111CDC 00022403 */   sra      $a0, $v0, 0x10
/* A83E0 80111CE0 0804473D */  j         .L80111CF4
/* A83E4 80111CE4 00000000 */   nop      
.L80111CE8:
/* A83E8 80111CE8 0C048338 */  jal       load_virtual_model
/* A83EC 80111CEC 8E440004 */   lw       $a0, 4($s2)
/* A83F0 80111CF0 A6020008 */  sh        $v0, 8($s0)
.L80111CF4:
/* A83F4 80111CF4 8E42000C */  lw        $v0, 0xc($s2)
/* A83F8 80111CF8 10400003 */  beqz      $v0, .L80111D08
/* A83FC 80111CFC 00000000 */   nop      
/* A8400 80111D00 0040F809 */  jalr      $v0
/* A8404 80111D04 0200202D */   daddu    $a0, $s0, $zero
.L80111D08:
/* A8408 80111D08 0C0440DD */  jal       update_shadow_transform_matrix
/* A840C 80111D0C 0200202D */   daddu    $a0, $s0, $zero
/* A8410 80111D10 92020004 */  lbu       $v0, 4($s0)
/* A8414 80111D14 8FBF001C */  lw        $ra, 0x1c($sp)
/* A8418 80111D18 8FB20018 */  lw        $s2, 0x18($sp)
/* A841C 80111D1C 8FB10014 */  lw        $s1, 0x14($sp)
/* A8420 80111D20 8FB00010 */  lw        $s0, 0x10($sp)
/* A8424 80111D24 D7B80030 */  ldc1      $f24, 0x30($sp)
/* A8428 80111D28 D7B60028 */  ldc1      $f22, 0x28($sp)
/* A842C 80111D2C D7B40020 */  ldc1      $f20, 0x20($sp)
/* A8430 80111D30 03E00008 */  jr        $ra
/* A8434 80111D34 27BD0038 */   addiu    $sp, $sp, 0x38
