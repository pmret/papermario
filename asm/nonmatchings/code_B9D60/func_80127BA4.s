.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_80127BA4
/* BE2A4 80127BA4 27BDFFA8 */  addiu     $sp, $sp, -0x58
/* BE2A8 80127BA8 0080402D */  daddu     $t0, $a0, $zero
/* BE2AC 80127BAC 2402000D */  addiu     $v0, $zero, 0xd
/* BE2B0 80127BB0 AFBF0050 */  sw        $ra, 0x50($sp)
/* BE2B4 80127BB4 910304F8 */  lbu       $v1, 0x4f8($t0)
/* BE2B8 80127BB8 3C013F80 */  lui       $at, 0x3f80
/* BE2BC 80127BBC 44810000 */  mtc1      $at, $f0
/* BE2C0 80127BC0 10620006 */  beq       $v1, $v0, .L80127BDC
/* BE2C4 80127BC4 0000482D */   daddu    $t1, $zero, $zero
/* BE2C8 80127BC8 2402000E */  addiu     $v0, $zero, 0xe
/* BE2CC 80127BCC 1062001D */  beq       $v1, $v0, .L80127C44
/* BE2D0 80127BD0 2862000F */   slti     $v0, $v1, 0xf
/* BE2D4 80127BD4 08049F2B */  j         .L80127CAC
/* BE2D8 80127BD8 00000000 */   nop      
.L80127BDC:
/* BE2DC 80127BDC 24050004 */  addiu     $a1, $zero, 4
/* BE2E0 80127BE0 91030509 */  lbu       $v1, 0x509($t0)
/* BE2E4 80127BE4 3C014059 */  lui       $at, 0x4059
/* BE2E8 80127BE8 44811800 */  mtc1      $at, $f3
/* BE2EC 80127BEC 44801000 */  mtc1      $zero, $f2
/* BE2F0 80127BF0 00A32023 */  subu      $a0, $a1, $v1
/* BE2F4 80127BF4 00041040 */  sll       $v0, $a0, 1
/* BE2F8 80127BF8 00444821 */  addu      $t1, $v0, $a0
/* BE2FC 80127BFC 3C028015 */  lui       $v0, %hi(D_8014C580)
/* BE300 80127C00 00431021 */  addu      $v0, $v0, $v1
/* BE304 80127C04 9042C580 */  lbu       $v0, %lo(D_8014C580)($v0)
/* BE308 80127C08 24630001 */  addiu     $v1, $v1, 1
/* BE30C 80127C0C A1030509 */  sb        $v1, 0x509($t0)
/* BE310 80127C10 44820000 */  mtc1      $v0, $f0
/* BE314 80127C14 00000000 */  nop       
/* BE318 80127C18 46800020 */  cvt.s.w   $f0, $f0
/* BE31C 80127C1C 46000021 */  cvt.d.s   $f0, $f0
/* BE320 80127C20 306200FF */  andi      $v0, $v1, 0xff
/* BE324 80127C24 46220003 */  div.d     $f0, $f0, $f2
/* BE328 80127C28 3C018015 */  lui       $at, %hi(D_8014C580)
/* BE32C 80127C2C 00220821 */  addu      $at, $at, $v0
/* BE330 80127C30 9022C580 */  lbu       $v0, %lo(D_8014C580)($at)
/* BE334 80127C34 1440001B */  bnez      $v0, .L80127CA4
/* BE338 80127C38 46200020 */   cvt.s.d  $f0, $f0
/* BE33C 80127C3C 08049F29 */  j         .L80127CA4
/* BE340 80127C40 A10504F8 */   sb       $a1, 0x4f8($t0)
.L80127C44:
/* BE344 80127C44 91020512 */  lbu       $v0, 0x512($t0)
/* BE348 80127C48 3C014059 */  lui       $at, 0x4059
/* BE34C 80127C4C 44811800 */  mtc1      $at, $f3
/* BE350 80127C50 44801000 */  mtc1      $zero, $f2
/* BE354 80127C54 00024823 */  negu      $t1, $v0
/* BE358 80127C58 3C038015 */  lui       $v1, %hi(D_8014C588)
/* BE35C 80127C5C 00621821 */  addu      $v1, $v1, $v0
/* BE360 80127C60 9063C588 */  lbu       $v1, %lo(D_8014C588)($v1)
/* BE364 80127C64 24420001 */  addiu     $v0, $v0, 1
/* BE368 80127C68 A1020512 */  sb        $v0, 0x512($t0)
/* BE36C 80127C6C 304200FF */  andi      $v0, $v0, 0xff
/* BE370 80127C70 3C018015 */  lui       $at, %hi(D_8014C588)
/* BE374 80127C74 00220821 */  addu      $at, $at, $v0
/* BE378 80127C78 9022C588 */  lbu       $v0, %lo(D_8014C588)($at)
/* BE37C 80127C7C 44830000 */  mtc1      $v1, $f0
/* BE380 80127C80 00000000 */  nop       
/* BE384 80127C84 46800020 */  cvt.s.w   $f0, $f0
/* BE388 80127C88 46000021 */  cvt.d.s   $f0, $f0
/* BE38C 80127C8C 46220003 */  div.d     $f0, $f0, $f2
/* BE390 80127C90 14400004 */  bnez      $v0, .L80127CA4
/* BE394 80127C94 46200020 */   cvt.s.d  $f0, $f0
/* BE398 80127C98 8D0204FC */  lw        $v0, 0x4fc($t0)
/* BE39C 80127C9C 34420001 */  ori       $v0, $v0, 1
/* BE3A0 80127CA0 AD0204FC */  sw        $v0, 0x4fc($t0)
.L80127CA4:
/* BE3A4 80127CA4 910304F8 */  lbu       $v1, 0x4f8($t0)
/* BE3A8 80127CA8 2862000F */  slti      $v0, $v1, 0xf
.L80127CAC:
/* BE3AC 80127CAC 1040002B */  beqz      $v0, .L80127D5C
/* BE3B0 80127CB0 2862000D */   slti     $v0, $v1, 0xd
/* BE3B4 80127CB4 1440002A */  bnez      $v0, .L80127D60
/* BE3B8 80127CB8 0100202D */   daddu    $a0, $t0, $zero
/* BE3BC 80127CBC 24040001 */  addiu     $a0, $zero, 1
/* BE3C0 80127CC0 24070038 */  addiu     $a3, $zero, 0x38
/* BE3C4 80127CC4 95030514 */  lhu       $v1, 0x514($t0)
/* BE3C8 80127CC8 240200A0 */  addiu     $v0, $zero, 0xa0
/* BE3CC 80127CCC 00831806 */  srlv      $v1, $v1, $a0
/* BE3D0 80127CD0 00431023 */  subu      $v0, $v0, $v1
/* BE3D4 80127CD4 A502045A */  sh        $v0, 0x45a($t0)
/* BE3D8 80127CD8 8506045A */  lh        $a2, 0x45a($t0)
/* BE3DC 80127CDC 00E0102D */  daddu     $v0, $a3, $zero
/* BE3E0 80127CE0 A502045C */  sh        $v0, 0x45c($t0)
/* BE3E4 80127CE4 AFA00010 */  sw        $zero, 0x10($sp)
/* BE3E8 80127CE8 95020514 */  lhu       $v0, 0x514($t0)
/* BE3EC 80127CEC 0000282D */  daddu     $a1, $zero, $zero
/* BE3F0 80127CF0 AFA20014 */  sw        $v0, 0x14($sp)
/* BE3F4 80127CF4 95030516 */  lhu       $v1, 0x516($t0)
/* BE3F8 80127CF8 240200FF */  addiu     $v0, $zero, 0xff
/* BE3FC 80127CFC E7A00024 */  swc1      $f0, 0x24($sp)
/* BE400 80127D00 E7A00028 */  swc1      $f0, 0x28($sp)
/* BE404 80127D04 44890000 */  mtc1      $t1, $f0
/* BE408 80127D08 00000000 */  nop       
/* BE40C 80127D0C 46800020 */  cvt.s.w   $f0, $f0
/* BE410 80127D10 AFA2001C */  sw        $v0, 0x1c($sp)
/* BE414 80127D14 3C028012 */  lui       $v0, %hi(D_80127B70)
/* BE418 80127D18 24427B70 */  addiu     $v0, $v0, %lo(D_80127B70)
/* BE41C 80127D1C AFA20038 */  sw        $v0, 0x38($sp)
/* BE420 80127D20 24020140 */  addiu     $v0, $zero, 0x140
/* BE424 80127D24 AFA20044 */  sw        $v0, 0x44($sp)
/* BE428 80127D28 240200F0 */  addiu     $v0, $zero, 0xf0
/* BE42C 80127D2C AFA00020 */  sw        $zero, 0x20($sp)
/* BE430 80127D30 AFA0002C */  sw        $zero, 0x2c($sp)
/* BE434 80127D34 AFA00030 */  sw        $zero, 0x30($sp)
/* BE438 80127D38 E7A00034 */  swc1      $f0, 0x34($sp)
/* BE43C 80127D3C AFA8003C */  sw        $t0, 0x3c($sp)
/* BE440 80127D40 AFA00040 */  sw        $zero, 0x40($sp)
/* BE444 80127D44 AFA20048 */  sw        $v0, 0x48($sp)
/* BE448 80127D48 AFA0004C */  sw        $zero, 0x4c($sp)
/* BE44C 80127D4C 0C03D4B8 */  jal       draw_box
/* BE450 80127D50 AFA30018 */   sw       $v1, 0x18($sp)
/* BE454 80127D54 08049F61 */  j         .L80127D84
/* BE458 80127D58 00000000 */   nop      
.L80127D5C:
/* BE45C 80127D5C 0100202D */  daddu     $a0, $t0, $zero
.L80127D60:
/* BE460 80127D60 84850456 */  lh        $a1, 0x456($a0)
/* BE464 80127D64 84860458 */  lh        $a2, 0x458($a0)
/* BE468 80127D68 9487046E */  lhu       $a3, 0x46e($a0)
/* BE46C 80127D6C 94830462 */  lhu       $v1, 0x462($a0)
/* BE470 80127D70 24020004 */  addiu     $v0, $zero, 4
/* BE474 80127D74 AFA20014 */  sw        $v0, 0x14($sp)
/* BE478 80127D78 AFA00018 */  sw        $zero, 0x18($sp)
/* BE47C 80127D7C 0C049F64 */  jal       func_80127D90
/* BE480 80127D80 AFA30010 */   sw       $v1, 0x10($sp)
.L80127D84:
/* BE484 80127D84 8FBF0050 */  lw        $ra, 0x50($sp)
/* BE488 80127D88 03E00008 */  jr        $ra
/* BE48C 80127D8C 27BD0058 */   addiu    $sp, $sp, 0x58
