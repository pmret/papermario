.include "macro.inc"

# assembler directives
.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches
.set gp=64     # allow use of 64-bit general purpose registers

.section .text, "ax"

glabel func_80218000_4CF1B0
/* 4CF1B0 80218000 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* 4CF1B4 80218004 AFBF0018 */  sw        $ra, 0x18($sp)
/* 4CF1B8 80218008 AFB10014 */  sw        $s1, 0x14($sp)
/* 4CF1BC 8021800C AFB00010 */  sw        $s0, 0x10($sp)
/* 4CF1C0 80218010 8C840148 */  lw        $a0, 0x148($a0)
/* 4CF1C4 80218014 0C09A75B */  jal       get_actor
/* 4CF1C8 80218018 00A0802D */   daddu    $s0, $a1, $zero
/* 4CF1CC 8021801C 12000003 */  beqz      $s0, .L8021802C
/* 4CF1D0 80218020 0040882D */   daddu    $s1, $v0, $zero
/* 4CF1D4 80218024 3C018022 */  lui       $at, %hi(D_80219040)
/* 4CF1D8 80218028 AC209040 */  sw        $zero, %lo(D_80219040)($at)
.L8021802C:
/* 4CF1DC 8021802C 3C108022 */  lui       $s0, %hi(D_80219040)
/* 4CF1E0 80218030 26109040 */  addiu     $s0, $s0, %lo(D_80219040)
/* 4CF1E4 80218034 8E020000 */  lw        $v0, ($s0)
/* 4CF1E8 80218038 2442000F */  addiu     $v0, $v0, 0xf
/* 4CF1EC 8021803C 44826000 */  mtc1      $v0, $f12
/* 4CF1F0 80218040 00000000 */  nop       
/* 4CF1F4 80218044 46806320 */  cvt.s.w   $f12, $f12
/* 4CF1F8 80218048 0C00A6C9 */  jal       clamp_angle
/* 4CF1FC 8021804C AE020000 */   sw       $v0, ($s0)
/* 4CF200 80218050 4600010D */  trunc.w.s $f4, $f0
/* 4CF204 80218054 44022000 */  mfc1      $v0, $f4
/* 4CF208 80218058 3C0140C9 */  lui       $at, 0x40c9
/* 4CF20C 8021805C 34210FD0 */  ori       $at, $at, 0xfd0
/* 4CF210 80218060 44810000 */  mtc1      $at, $f0
/* 4CF214 80218064 44826000 */  mtc1      $v0, $f12
/* 4CF218 80218068 00000000 */  nop       
/* 4CF21C 8021806C 46806320 */  cvt.s.w   $f12, $f12
/* 4CF220 80218070 46006302 */  mul.s     $f12, $f12, $f0
/* 4CF224 80218074 00000000 */  nop       
/* 4CF228 80218078 3C0143B4 */  lui       $at, 0x43b4
/* 4CF22C 8021807C 44810000 */  mtc1      $at, $f0
/* 4CF230 80218080 AE020000 */  sw        $v0, ($s0)
/* 4CF234 80218084 0C00A85B */  jal       sin_rad
/* 4CF238 80218088 46006303 */   div.s    $f12, $f12, $f0
/* 4CF23C 8021808C 3C014040 */  lui       $at, 0x4040
/* 4CF240 80218090 44811000 */  mtc1      $at, $f2
/* 4CF244 80218094 00000000 */  nop       
/* 4CF248 80218098 46020002 */  mul.s     $f0, $f0, $f2
/* 4CF24C 8021809C 00000000 */  nop       
/* 4CF250 802180A0 4600010D */  trunc.w.s $f4, $f0
/* 4CF254 802180A4 44032000 */  mfc1      $v1, $f4
/* 4CF258 802180A8 00000000 */  nop       
/* 4CF25C 802180AC A223019A */  sb        $v1, 0x19a($s1)
/* 4CF260 802180B0 8FBF0018 */  lw        $ra, 0x18($sp)
/* 4CF264 802180B4 8FB10014 */  lw        $s1, 0x14($sp)
/* 4CF268 802180B8 8FB00010 */  lw        $s0, 0x10($sp)
/* 4CF26C 802180BC 0000102D */  daddu     $v0, $zero, $zero
/* 4CF270 802180C0 03E00008 */  jr        $ra
/* 4CF274 802180C4 27BD0020 */   addiu    $sp, $sp, 0x20

glabel func_802180C8_4CF278
/* 4CF278 802180C8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF27C 802180CC AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CF280 802180D0 0C03A698 */  jal       status_menu_start_blinking_sp
/* 4CF284 802180D4 00000000 */   nop      
/* 4CF288 802180D8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4CF28C 802180DC 24020002 */  addiu     $v0, $zero, 2
/* 4CF290 802180E0 03E00008 */  jr        $ra
/* 4CF294 802180E4 27BD0018 */   addiu    $sp, $sp, 0x18

glabel func_802180E8_4CF298
/* 4CF298 802180E8 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF29C 802180EC AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CF2A0 802180F0 0C03A6A5 */  jal       status_menu_stop_blinking_sp
/* 4CF2A4 802180F4 00000000 */   nop      
/* 4CF2A8 802180F8 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4CF2AC 802180FC 24020002 */  addiu     $v0, $zero, 2
/* 4CF2B0 80218100 03E00008 */  jr        $ra
/* 4CF2B4 80218104 27BD0018 */   addiu    $sp, $sp, 0x18

glabel func_80218108_4CF2B8
/* 4CF2B8 80218108 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF2BC 8021810C AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CF2C0 80218110 0C03A648 */  jal       status_menu_start_blinking_hp
/* 4CF2C4 80218114 00000000 */   nop      
/* 4CF2C8 80218118 0C03A663 */  jal       status_menu_start_blinking_fp
/* 4CF2CC 8021811C 00000000 */   nop      
/* 4CF2D0 80218120 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4CF2D4 80218124 24020002 */  addiu     $v0, $zero, 2
/* 4CF2D8 80218128 03E00008 */  jr        $ra
/* 4CF2DC 8021812C 27BD0018 */   addiu    $sp, $sp, 0x18

glabel func_80218130_4CF2E0
/* 4CF2E0 80218130 27BDFFE8 */  addiu     $sp, $sp, -0x18
/* 4CF2E4 80218134 AFBF0010 */  sw        $ra, 0x10($sp)
/* 4CF2E8 80218138 0C03A659 */  jal       status_menu_stop_blinking_hp
/* 4CF2EC 8021813C 00000000 */   nop      
/* 4CF2F0 80218140 0C03A674 */  jal       status_menu_stop_blinking_fp
/* 4CF2F4 80218144 00000000 */   nop      
/* 4CF2F8 80218148 8FBF0010 */  lw        $ra, 0x10($sp)
/* 4CF2FC 8021814C 24020002 */  addiu     $v0, $zero, 2
/* 4CF300 80218150 03E00008 */  jr        $ra
/* 4CF304 80218154 27BD0018 */   addiu    $sp, $sp, 0x18

glabel func_80218158_4CF308
/* 4CF308 80218158 3C02800E */  lui       $v0, %hi(gBattleStatus)
/* 4CF30C 8021815C 2442C070 */  addiu     $v0, $v0, %lo(gBattleStatus)
/* 4CF310 80218160 A040004C */  sb        $zero, 0x4c($v0)
/* 4CF314 80218164 A040005C */  sb        $zero, 0x5c($v0)
/* 4CF318 80218168 03E00008 */  jr        $ra
/* 4CF31C 8021816C 24020002 */   addiu    $v0, $zero, 2

glabel func_80218170_4CF320
/* 4CF320 80218170 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 4CF324 80218174 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 4CF328 80218178 10A00002 */  beqz      $a1, .L80218184
/* 4CF32C 8021817C 2402000A */   addiu    $v0, $zero, 0xa
/* 4CF330 80218180 AC820070 */  sw        $v0, 0x70($a0)
.L80218184:
/* 4CF334 80218184 8CC20004 */  lw        $v0, 4($a2)
/* 4CF338 80218188 2403FFFD */  addiu     $v1, $zero, -3
/* 4CF33C 8021818C 00431024 */  and       $v0, $v0, $v1
/* 4CF340 80218190 ACC20004 */  sw        $v0, 4($a2)
/* 4CF344 80218194 8C820070 */  lw        $v0, 0x70($a0)
/* 4CF348 80218198 14400003 */  bnez      $v0, .L802181A8
/* 4CF34C 8021819C 2442FFFF */   addiu    $v0, $v0, -1
/* 4CF350 802181A0 03E00008 */  jr        $ra
/* 4CF354 802181A4 24020002 */   addiu    $v0, $zero, 2
.L802181A8:
/* 4CF358 802181A8 AC820070 */  sw        $v0, 0x70($a0)
/* 4CF35C 802181AC 03E00008 */  jr        $ra
/* 4CF360 802181B0 0000102D */   daddu    $v0, $zero, $zero

glabel func_802181B4_4CF364
/* 4CF364 802181B4 3C06800E */  lui       $a2, %hi(gBattleStatus)
/* 4CF368 802181B8 24C6C070 */  addiu     $a2, $a2, %lo(gBattleStatus)
/* 4CF36C 802181BC 10A00002 */  beqz      $a1, .L802181C8
/* 4CF370 802181C0 2402000A */   addiu    $v0, $zero, 0xa
/* 4CF374 802181C4 AC820070 */  sw        $v0, 0x70($a0)
.L802181C8:
/* 4CF378 802181C8 8CC20004 */  lw        $v0, 4($a2)
/* 4CF37C 802181CC 2403FFFB */  addiu     $v1, $zero, -5
/* 4CF380 802181D0 00431024 */  and       $v0, $v0, $v1
/* 4CF384 802181D4 ACC20004 */  sw        $v0, 4($a2)
/* 4CF388 802181D8 8C820070 */  lw        $v0, 0x70($a0)
/* 4CF38C 802181DC 14400003 */  bnez      $v0, .L802181EC
/* 4CF390 802181E0 2442FFFF */   addiu    $v0, $v0, -1
/* 4CF394 802181E4 03E00008 */  jr        $ra
/* 4CF398 802181E8 24020002 */   addiu    $v0, $zero, 2
.L802181EC:
/* 4CF39C 802181EC AC820070 */  sw        $v0, 0x70($a0)
/* 4CF3A0 802181F0 03E00008 */  jr        $ra
/* 4CF3A4 802181F4 0000102D */   daddu    $v0, $zero, $zero

glabel func_802181F8_4CF3A8
/* 4CF3A8 802181F8 3C038011 */  lui       $v1, %hi(gPlayerData)
/* 4CF3AC 802181FC 2463F290 */  addiu     $v1, $v1, %lo(gPlayerData)
/* 4CF3B0 80218200 94620290 */  lhu       $v0, 0x290($v1)
/* 4CF3B4 80218204 24420020 */  addiu     $v0, $v0, 0x20
/* 4CF3B8 80218208 A4620290 */  sh        $v0, 0x290($v1)
/* 4CF3BC 8021820C 03E00008 */  jr        $ra
/* 4CF3C0 80218210 24020002 */   addiu    $v0, $zero, 2
/* 4CF3C4 80218214 00000000 */  nop       
/* 4CF3C8 80218218 00000000 */  nop       
/* 4CF3CC 8021821C 00000000 */  nop       

glabel func_80218220_4CF3D0
/* 4CF3D0 80218220 80218368 */  lb        $at, -0x7c98($at)
/* 4CF3D4 80218224 00000006 */  srlv      $zero, $zero, $zero
/* 4CF3D8 80218228 0000000A */  movz      $zero, $zero, $zero
/* 4CF3DC 8021822C 00000000 */  nop       
/* 4CF3E0 80218230 00000000 */  nop       
/* 4CF3E4 80218234 00000000 */  nop       
/* 4CF3E8 80218238 00000000 */  nop       
/* 4CF3EC 8021823C 80218FF0 */  lb        $at, -0x7010($at)
/* 4CF3F0 80218240 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF3F4 80218244 80218220 */  lb        $at, -0x7de0($at)
/* 4CF3F8 80218248 80218FC0 */  lb        $at, -0x7040($at)
/* 4CF3FC 8021824C 00000000 */  nop       
/* 4CF400 80218250 00000000 */  nop       
/* 4CF404 80218254 00000000 */  nop       
/* 4CF408 80218258 00000000 */  nop       
/* 4CF40C 8021825C 00000000 */  nop       
/* 4CF410 80218260 00000000 */  nop       
/* 4CF414 80218264 80219008 */  lb        $at, -0x6ff8($at)
/* 4CF418 80218268 80218FC0 */  lb        $at, -0x7040($at)
/* 4CF41C 8021826C 00000000 */  nop       
/* 4CF420 80218270 00000000 */  nop       
/* 4CF424 80218274 00000000 */  nop       
/* 4CF428 80218278 00000000 */  nop       
/* 4CF42C 8021827C 00000000 */  nop       
/* 4CF430 80218280 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF434 80218284 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CF438 80218288 00000000 */  nop       
/* 4CF43C 8021828C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF440 80218290 00000000 */  nop       
/* 4CF444 80218294 00000000 */  nop       
/* 4CF448 80218298 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF44C 8021829C 00000000 */  nop       
/* 4CF450 802182A0 00000002 */  srl       $zero, $zero, 0
/* 4CF454 802182A4 00000000 */  nop       
/* 4CF458 802182A8 00000006 */  srlv      $zero, $zero, $zero
/* 4CF45C 802182AC 00000000 */  nop       
/* 4CF460 802182B0 00000009 */  jr        $zero
/* 4CF464 802182B4 00000000 */   nop      

glabel func_802182B8_4CF468
/* 4CF468 802182B8 00000007 */  srav      $zero, $zero, $zero
/* 4CF46C 802182BC 00000000 */  nop       
/* 4CF470 802182C0 00000004 */  sllv      $zero, $zero, $zero
/* 4CF474 802182C4 00000000 */  nop       
/* 4CF478 802182C8 00000003 */  sra       $zero, $zero, 0
/* 4CF47C 802182CC 00000000 */  nop       
/* 4CF480 802182D0 0000000B */  movn      $zero, $zero, $zero
/* 4CF484 802182D4 00000000 */  nop       
/* 4CF488 802182D8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CF48C 802182DC 00000000 */  nop       
/* 4CF490 802182E0 0000000A */  movz      $zero, $zero, $zero
/* 4CF494 802182E4 00000000 */  nop       
/* 4CF498 802182E8 00000008 */  jr        $zero
/* 4CF49C 802182EC 00000000 */   nop      

glabel func_802182F0_4CF4A0
/* 4CF4A0 802182F0 0000001F */  ddivu     $zero, $zero, $zero
/* 4CF4A4 802182F4 00000000 */  nop       
/* 4CF4A8 802182F8 00000020 */  add       $zero, $zero, $zero
/* 4CF4AC 802182FC 00000000 */  nop       
/* 4CF4B0 80218300 00000025 */  or        $zero, $zero, $zero
/* 4CF4B4 80218304 00000000 */  nop       
/* 4CF4B8 80218308 00000022 */  neg       $zero, $zero
/* 4CF4BC 8021830C 00000000 */  nop       
/* 4CF4C0 80218310 00000024 */  and       $zero, $zero, $zero
/* 4CF4C4 80218314 00000000 */  nop       
/* 4CF4C8 80218318 00000023 */  negu      $zero, $zero
/* 4CF4CC 8021831C 00000000 */  nop       
/* 4CF4D0 80218320 00000021 */  addu      $zero, $zero, $zero
/* 4CF4D4 80218324 00000000 */  nop       
/* 4CF4D8 80218328 00000026 */  xor       $zero, $zero, $zero
/* 4CF4DC 8021832C 00000000 */  nop       
/* 4CF4E0 80218330 00000027 */  not       $zero, $zero
/* 4CF4E4 80218334 00000000 */  nop       
/* 4CF4E8 80218338 00000029 */  .byte     0x00, 0x00, 0x00, 0x29
/* 4CF4EC 8021833C 00000000 */  nop       
/* 4CF4F0 80218340 00000000 */  nop       
/* 4CF4F4 80218344 00800000 */  .byte     0x00, 0x80, 0x00, 0x00
/* 4CF4F8 80218348 01000000 */  .byte     0x01, 0x00, 0x00, 0x00
/* 4CF4FC 8021834C 001800FF */  dsra32    $zero, $t8, 3
/* 4CF500 80218350 80218280 */  lb        $at, -0x7d80($at)
/* 4CF504 80218354 8021828C */  lb        $at, -0x7d74($at)
/* 4CF508 80218358 00000000 */  nop       
/* 4CF50C 8021835C 00000000 */  nop       
/* 4CF510 80218360 00000000 */  nop       
/* 4CF514 80218364 00000000 */  nop       
/* 4CF518 80218368 00240000 */  .byte     0x00, 0x24, 0x00, 0x00
/* 4CF51C 8021836C 009F6363 */  .byte     0x00, 0x9f, 0x63, 0x63
/* 4CF520 80218370 00010000 */  sll       $zero, $at, 0
/* 4CF524 80218374 80218344 */  lb        $at, -0x7cbc($at)
/* 4CF528 80218378 80218390 */  lb        $at, -0x7c70($at)
/* 4CF52C 8021837C 80218298 */  lb        $at, -0x7d68($at)
/* 4CF530 80218380 00000000 */  nop       
/* 4CF534 80218384 00006400 */  sll       $t4, $zero, 0x10
/* 4CF538 80218388 18200000 */  blez      $at, .L8021838C
.L8021838C:
/* 4CF53C 8021838C F6140A14 */   sdc1     $f20, 0xa14($s0)
/* 4CF540 80218390 00000043 */  sra       $zero, $zero, 1
/* 4CF544 80218394 00000003 */  sra       $zero, $zero, 0
/* 4CF548 80218398 80278930 */  lb        $a3, -0x76d0($at)
/* 4CF54C 8021839C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF550 802183A0 80218414 */  lb        $at, -0x7bec($at)
/* 4CF554 802183A4 00000043 */  sra       $zero, $zero, 1
/* 4CF558 802183A8 00000003 */  sra       $zero, $zero, 0
/* 4CF55C 802183AC 80278A94 */  lb        $a3, -0x756c($at)
/* 4CF560 802183B0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF564 802183B4 802183E8 */  lb        $at, -0x7c18($at)
/* 4CF568 802183B8 00000043 */  sra       $zero, $zero, 1
/* 4CF56C 802183BC 00000003 */  sra       $zero, $zero, 0
/* 4CF570 802183C0 80278C20 */  lb        $a3, -0x73e0($at)
/* 4CF574 802183C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF578 802183C8 80218404 */  lb        $at, -0x7bfc($at)
/* 4CF57C 802183CC 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4CF580 802183D0 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF584 802183D4 80218424 */  lb        $at, -0x7bdc($at)
/* 4CF588 802183D8 00000002 */  srl       $zero, $zero, 0
/* 4CF58C 802183DC 00000000 */  nop       
/* 4CF590 802183E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF594 802183E4 00000000 */  nop       
/* 4CF598 802183E8 00000043 */  sra       $zero, $zero, 1
/* 4CF59C 802183EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF5A0 802183F0 80218000 */  lb        $at, -0x8000($at)
/* 4CF5A4 802183F4 00000002 */  srl       $zero, $zero, 0
/* 4CF5A8 802183F8 00000000 */  nop       
/* 4CF5AC 802183FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF5B0 80218400 00000000 */  nop       
/* 4CF5B4 80218404 00000002 */  srl       $zero, $zero, 0
/* 4CF5B8 80218408 00000000 */  nop       
/* 4CF5BC 8021840C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF5C0 80218410 00000000 */  nop       
/* 4CF5C4 80218414 00000002 */  srl       $zero, $zero, 0
/* 4CF5C8 80218418 00000000 */  nop       
/* 4CF5CC 8021841C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF5D0 80218420 00000000 */  nop       
/* 4CF5D4 80218424 00000043 */  sra       $zero, $zero, 1
/* 4CF5D8 80218428 00000003 */  sra       $zero, $zero, 0
/* 4CF5DC 8021842C 8026CD3C */  lb        $a2, -0x32c4($at)
/* 4CF5E0 80218430 02000000 */  .byte     0x02, 0x00, 0x00, 0x00
/* 4CF5E4 80218434 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF5E8 80218438 00000043 */  sra       $zero, $zero, 1
/* 4CF5EC 8021843C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF5F0 80218440 80218158 */  lb        $at, -0x7ea8($at)
/* 4CF5F4 80218444 00000043 */  sra       $zero, $zero, 1
/* 4CF5F8 80218448 00000002 */  srl       $zero, $zero, 0
/* 4CF5FC 8021844C 8026E198 */  lb        $a2, -0x1e68($at)
/* 4CF600 80218450 0000000D */  break     
/* 4CF604 80218454 00000043 */   sra      $zero, $zero, 1
/* 4CF608 80218458 00000004 */  sllv      $zero, $zero, $zero
/* 4CF60C 8021845C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CF610 80218460 00000000 */  nop       
/* 4CF614 80218464 00000000 */  nop       
/* 4CF618 80218468 00010002 */  srl       $zero, $at, 0
/* 4CF61C 8021846C 00000008 */  jr        $zero
/* 4CF620 80218470 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218474_4CF624
/* 4CF624 80218474 0000000F */  sync      
/* 4CF628 80218478 00000043 */  sra       $zero, $zero, 1
/* 4CF62C 8021847C 00000003 */  sra       $zero, $zero, 0
/* 4CF630 80218480 8026F0EC */  lb        $a2, -0xf14($at)
/* 4CF634 80218484 00000000 */  nop       
/* 4CF638 80218488 00000000 */  nop       
/* 4CF63C 8021848C 00000043 */  sra       $zero, $zero, 1
/* 4CF640 80218490 00000006 */  srlv      $zero, $zero, $zero
/* 4CF644 80218494 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CF648 80218498 000C0114 */  .byte     0x00, 0x0c, 0x01, 0x14
/* 4CF64C 8021849C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF650 802184A0 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF654 802184A4 00120002 */  srl       $zero, $s2, 0
/* 4CF658 802184A8 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CF65C 802184AC 00000056 */  drotrv    $zero, $zero, $zero
/* 4CF660 802184B0 00000000 */  nop       
/* 4CF664 802184B4 00000043 */  sra       $zero, $zero, 1
/* 4CF668 802184B8 00000003 */  sra       $zero, $zero, 0
/* 4CF66C 802184BC 8027D57C */  lb        $a3, -0x2a84($at)
/* 4CF670 802184C0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF674 802184C4 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF678 802184C8 00000043 */  sra       $zero, $zero, 1
/* 4CF67C 802184CC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CF680 802184D0 8026A510 */  lb        $a2, -0x5af0($at)
/* 4CF684 802184D4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF688 802184D8 FFFFFF92 */  sd        $ra, -0x6e($ra)
/* 4CF68C 802184DC 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4CF690 802184E0 00000000 */  nop       
/* 4CF694 802184E4 00000043 */  sra       $zero, $zero, 1
/* 4CF698 802184E8 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CF69C 802184EC 8027B624 */  lb        $a3, -0x49dc($at)
/* 4CF6A0 802184F0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF6A4 802184F4 00000014 */  dsllv     $zero, $zero, $zero
/* 4CF6A8 802184F8 00000000 */  nop       
/* 4CF6AC 802184FC 0000000A */  movz      $zero, $zero, $zero
/* 4CF6B0 80218500 00000043 */  sra       $zero, $zero, 1
/* 4CF6B4 80218504 00000003 */  sra       $zero, $zero, 0
/* 4CF6B8 80218508 8027D57C */  lb        $a3, -0x2a84($at)
/* 4CF6BC 8021850C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF6C0 80218510 00000000 */  nop       
/* 4CF6C4 80218514 00000043 */  sra       $zero, $zero, 1
/* 4CF6C8 80218518 00000004 */  sllv      $zero, $zero, $zero
/* 4CF6CC 8021851C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CF6D0 80218520 00000000 */  nop       
/* 4CF6D4 80218524 00000000 */  nop       
/* 4CF6D8 80218528 0001002A */  slt       $zero, $zero, $at
/* 4CF6DC 8021852C 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4CF6E0 80218530 00000000 */  nop       
/* 4CF6E4 80218534 00000008 */  jr        $zero
/* 4CF6E8 80218538 00000001 */   movf     $zero, $zero, $fcc0

glabel func_8021853C_4CF6EC
/* 4CF6EC 8021853C 0000000A */  movz      $zero, $zero, $zero
/* 4CF6F0 80218540 00000043 */  sra       $zero, $zero, 1
/* 4CF6F4 80218544 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF6F8 80218548 802180C8 */  lb        $at, -0x7f38($at)
/* 4CF6FC 8021854C 00000008 */  jr        $zero
/* 4CF700 80218550 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218554_4CF704
/* 4CF704 80218554 00000078 */  dsll      $zero, $zero, 1
/* 4CF708 80218558 00000043 */  sra       $zero, $zero, 1
/* 4CF70C 8021855C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF710 80218560 802180E8 */  lb        $at, -0x7f18($at)
/* 4CF714 80218564 00000043 */  sra       $zero, $zero, 1
/* 4CF718 80218568 00000004 */  sllv      $zero, $zero, $zero
/* 4CF71C 8021856C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CF720 80218570 00000000 */  nop       
/* 4CF724 80218574 00000000 */  nop       
/* 4CF728 80218578 00010002 */  srl       $zero, $at, 0
/* 4CF72C 8021857C 00000043 */  sra       $zero, $zero, 1
/* 4CF730 80218580 00000002 */  srl       $zero, $zero, 0
/* 4CF734 80218584 80269EC4 */  lb        $a2, -0x613c($at)
/* 4CF738 80218588 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF73C 8021858C 00000043 */  sra       $zero, $zero, 1
/* 4CF740 80218590 00000003 */  sra       $zero, $zero, 0
/* 4CF744 80218594 8027D57C */  lb        $a3, -0x2a84($at)
/* 4CF748 80218598 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF74C 8021859C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF750 802185A0 00000043 */  sra       $zero, $zero, 1
/* 4CF754 802185A4 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CF758 802185A8 8027B624 */  lb        $a3, -0x49dc($at)
/* 4CF75C 802185AC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF760 802185B0 00000014 */  dsllv     $zero, $zero, $zero
/* 4CF764 802185B4 00000000 */  nop       
/* 4CF768 802185B8 0000000A */  movz      $zero, $zero, $zero
/* 4CF76C 802185BC 00000043 */  sra       $zero, $zero, 1
/* 4CF770 802185C0 00000003 */  sra       $zero, $zero, 0
/* 4CF774 802185C4 8027D57C */  lb        $a3, -0x2a84($at)
/* 4CF778 802185C8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF77C 802185CC 00000000 */  nop       
/* 4CF780 802185D0 00000043 */  sra       $zero, $zero, 1
/* 4CF784 802185D4 00000006 */  srlv      $zero, $zero, $zero
/* 4CF788 802185D8 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CF78C 802185DC 000C0115 */  .byte     0x00, 0x0c, 0x01, 0x15
/* 4CF790 802185E0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF794 802185E4 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF798 802185E8 00120002 */  srl       $zero, $s2, 0
/* 4CF79C 802185EC 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CF7A0 802185F0 00000008 */  jr        $zero
/* 4CF7A4 802185F4 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802185F8_4CF7A8
/* 4CF7A8 802185F8 0000000A */  movz      $zero, $zero, $zero
/* 4CF7AC 802185FC 00000043 */  sra       $zero, $zero, 1
/* 4CF7B0 80218600 00000004 */  sllv      $zero, $zero, $zero
/* 4CF7B4 80218604 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CF7B8 80218608 00000000 */  nop       
/* 4CF7BC 8021860C 00000000 */  nop       
/* 4CF7C0 80218610 0001002A */  slt       $zero, $zero, $at
/* 4CF7C4 80218614 00000043 */  sra       $zero, $zero, 1
/* 4CF7C8 80218618 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF7CC 8021861C 802180C8 */  lb        $at, -0x7f38($at)
/* 4CF7D0 80218620 00000008 */  jr        $zero
/* 4CF7D4 80218624 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218628_4CF7D8
/* 4CF7D8 80218628 00000078 */  dsll      $zero, $zero, 1
/* 4CF7DC 8021862C 00000043 */  sra       $zero, $zero, 1
/* 4CF7E0 80218630 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF7E4 80218634 802180E8 */  lb        $at, -0x7f18($at)
/* 4CF7E8 80218638 00000043 */  sra       $zero, $zero, 1
/* 4CF7EC 8021863C 00000004 */  sllv      $zero, $zero, $zero
/* 4CF7F0 80218640 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CF7F4 80218644 00000000 */  nop       
/* 4CF7F8 80218648 00000000 */  nop       
/* 4CF7FC 8021864C 00010002 */  srl       $zero, $at, 0
/* 4CF800 80218650 00000043 */  sra       $zero, $zero, 1
/* 4CF804 80218654 00000006 */  srlv      $zero, $zero, $zero
/* 4CF808 80218658 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CF80C 8021865C 000C0116 */  .byte     0x00, 0x0c, 0x01, 0x16
/* 4CF810 80218660 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF814 80218664 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF818 80218668 00120002 */  srl       $zero, $s2, 0
/* 4CF81C 8021866C 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CF820 80218670 00000008 */  jr        $zero
/* 4CF824 80218674 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218678_4CF828
/* 4CF828 80218678 0000000A */  movz      $zero, $zero, $zero
/* 4CF82C 8021867C 00000043 */  sra       $zero, $zero, 1
/* 4CF830 80218680 00000002 */  srl       $zero, $zero, 0
/* 4CF834 80218684 8026E020 */  lb        $a2, -0x1fe0($at)
/* 4CF838 80218688 00000100 */  sll       $zero, $zero, 4
/* 4CF83C 8021868C 00000043 */  sra       $zero, $zero, 1
/* 4CF840 80218690 00000002 */  srl       $zero, $zero, 0
/* 4CF844 80218694 8026E038 */  lb        $a2, -0x1fc8($at)
/* 4CF848 80218698 00000002 */  srl       $zero, $zero, 0
/* 4CF84C 8021869C 00000043 */  sra       $zero, $zero, 1
/* 4CF850 802186A0 00000002 */  srl       $zero, $zero, 0
/* 4CF854 802186A4 8026E198 */  lb        $a2, -0x1e68($at)
/* 4CF858 802186A8 00000012 */  mflo      $zero
/* 4CF85C 802186AC 00000024 */  and       $zero, $zero, $zero
/* 4CF860 802186B0 00000002 */  srl       $zero, $zero, 0
/* 4CF864 802186B4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF868 802186B8 000000FF */  dsra32    $zero, $zero, 3
/* 4CF86C 802186BC 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CF870 802186C0 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF874 802186C4 0000000A */  movz      $zero, $zero, $zero
/* 4CF878 802186C8 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4CF87C 802186CC 00000002 */  srl       $zero, $zero, 0
/* 4CF880 802186D0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF884 802186D4 00000019 */  multu     $zero, $zero
/* 4CF888 802186D8 0000000C */  syscall   
/* 4CF88C 802186DC 00000002 */  srl       $zero, $zero, 0
/* 4CF890 802186E0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF894 802186E4 00000000 */  nop       
/* 4CF898 802186E8 00000024 */  and       $zero, $zero, $zero
/* 4CF89C 802186EC 00000002 */  srl       $zero, $zero, 0
/* 4CF8A0 802186F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF8A4 802186F4 00000000 */  nop       
/* 4CF8A8 802186F8 00000013 */  mtlo      $zero
/* 4CF8AC 802186FC 00000000 */  nop       
/* 4CF8B0 80218700 00000043 */  sra       $zero, $zero, 1
/* 4CF8B4 80218704 00000004 */  sllv      $zero, $zero, $zero
/* 4CF8B8 80218708 8026F470 */  lb        $a2, -0xb90($at)
/* 4CF8BC 8021870C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF8C0 80218710 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF8C4 80218714 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF8C8 80218718 00000008 */  jr        $zero
/* 4CF8CC 8021871C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218720_4CF8D0
/* 4CF8D0 80218720 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF8D4 80218724 00000006 */  srlv      $zero, $zero, $zero
/* 4CF8D8 80218728 00000000 */  nop       
/* 4CF8DC 8021872C 00000043 */  sra       $zero, $zero, 1
/* 4CF8E0 80218730 00000004 */  sllv      $zero, $zero, $zero
/* 4CF8E4 80218734 8026F470 */  lb        $a2, -0xb90($at)
/* 4CF8E8 80218738 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF8EC 8021873C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF8F0 80218740 00000000 */  nop       
/* 4CF8F4 80218744 00000043 */  sra       $zero, $zero, 1
/* 4CF8F8 80218748 00000004 */  sllv      $zero, $zero, $zero
/* 4CF8FC 8021874C 8026CE8C */  lb        $a2, -0x3174($at)
/* 4CF900 80218750 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF904 80218754 00000004 */  sllv      $zero, $zero, $zero
/* 4CF908 80218758 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF90C 8021875C 00000056 */  drotrv    $zero, $zero, $zero
/* 4CF910 80218760 00000000 */  nop       
/* 4CF914 80218764 00000043 */  sra       $zero, $zero, 1
/* 4CF918 80218768 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF91C 8021876C 80218170 */  lb        $at, -0x7e90($at)
/* 4CF920 80218770 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4CF924 80218774 00000000 */  nop       
/* 4CF928 80218778 00000043 */  sra       $zero, $zero, 1
/* 4CF92C 8021877C 00000002 */  srl       $zero, $zero, 0
/* 4CF930 80218780 8026E198 */  lb        $a2, -0x1e68($at)
/* 4CF934 80218784 00000016 */  dsrlv     $zero, $zero, $zero
/* 4CF938 80218788 00000024 */  and       $zero, $zero, $zero
/* 4CF93C 8021878C 00000002 */  srl       $zero, $zero, 0
/* 4CF940 80218790 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF944 80218794 00000000 */  nop       
/* 4CF948 80218798 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CF94C 8021879C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF950 802187A0 0000000A */  movz      $zero, $zero, $zero
/* 4CF954 802187A4 00000027 */  not       $zero, $zero
/* 4CF958 802187A8 00000002 */  srl       $zero, $zero, 0
/* 4CF95C 802187AC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF960 802187B0 00000019 */  multu     $zero, $zero
/* 4CF964 802187B4 0000000D */  break     
/* 4CF968 802187B8 00000002 */   srl      $zero, $zero, 0
/* 4CF96C 802187BC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF970 802187C0 000000FF */  dsra32    $zero, $zero, 3
/* 4CF974 802187C4 00000024 */  and       $zero, $zero, $zero
/* 4CF978 802187C8 00000002 */  srl       $zero, $zero, 0
/* 4CF97C 802187CC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF980 802187D0 000000FF */  dsra32    $zero, $zero, 3
/* 4CF984 802187D4 00000013 */  mtlo      $zero
/* 4CF988 802187D8 00000000 */  nop       
/* 4CF98C 802187DC 00000043 */  sra       $zero, $zero, 1
/* 4CF990 802187E0 00000004 */  sllv      $zero, $zero, $zero
/* 4CF994 802187E4 8026F470 */  lb        $a2, -0xb90($at)
/* 4CF998 802187E8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF99C 802187EC 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF9A0 802187F0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CF9A4 802187F4 00000008 */  jr        $zero
/* 4CF9A8 802187F8 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802187FC_4CF9AC
/* 4CF9AC 802187FC 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF9B0 80218800 00000006 */  srlv      $zero, $zero, $zero
/* 4CF9B4 80218804 00000000 */  nop       
/* 4CF9B8 80218808 00000043 */  sra       $zero, $zero, 1
/* 4CF9BC 8021880C 00000004 */  sllv      $zero, $zero, $zero
/* 4CF9C0 80218810 8026F470 */  lb        $a2, -0xb90($at)
/* 4CF9C4 80218814 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF9C8 80218818 00000001 */  movf      $zero, $zero, $fcc0
/* 4CF9CC 8021881C 000000FF */  dsra32    $zero, $zero, 3
/* 4CF9D0 80218820 00000043 */  sra       $zero, $zero, 1
/* 4CF9D4 80218824 00000004 */  sllv      $zero, $zero, $zero
/* 4CF9D8 80218828 8026CE8C */  lb        $a2, -0x3174($at)
/* 4CF9DC 8021882C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF9E0 80218830 00000004 */  sllv      $zero, $zero, $zero
/* 4CF9E4 80218834 00000000 */  nop       
/* 4CF9E8 80218838 00000043 */  sra       $zero, $zero, 1
/* 4CF9EC 8021883C 00000006 */  srlv      $zero, $zero, $zero
/* 4CF9F0 80218840 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CF9F4 80218844 000C0117 */  .byte     0x00, 0x0c, 0x01, 0x17
/* 4CF9F8 80218848 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CF9FC 8021884C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFA00 80218850 00120002 */  srl       $zero, $s2, 0
/* 4CFA04 80218854 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CFA08 80218858 00000008 */  jr        $zero
/* 4CFA0C 8021885C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218860_4CFA10
/* 4CFA10 80218860 0000000A */  movz      $zero, $zero, $zero
/* 4CFA14 80218864 00000043 */  sra       $zero, $zero, 1
/* 4CFA18 80218868 00000003 */  sra       $zero, $zero, 0
/* 4CFA1C 8021886C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4CFA20 80218870 00000000 */  nop       
/* 4CFA24 80218874 00000000 */  nop       
/* 4CFA28 80218878 00000043 */  sra       $zero, $zero, 1
/* 4CFA2C 8021887C 00000004 */  sllv      $zero, $zero, $zero
/* 4CFA30 80218880 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CFA34 80218884 00000000 */  nop       
/* 4CFA38 80218888 00000000 */  nop       
/* 4CFA3C 8021888C 0001002A */  slt       $zero, $zero, $at
/* 4CFA40 80218890 00000043 */  sra       $zero, $zero, 1
/* 4CFA44 80218894 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFA48 80218898 802180C8 */  lb        $at, -0x7f38($at)
/* 4CFA4C 8021889C 00000008 */  jr        $zero
/* 4CFA50 802188A0 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802188A4_4CFA54
/* 4CFA54 802188A4 00000078 */  dsll      $zero, $zero, 1
/* 4CFA58 802188A8 00000043 */  sra       $zero, $zero, 1
/* 4CFA5C 802188AC 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFA60 802188B0 802180E8 */  lb        $at, -0x7f18($at)
/* 4CFA64 802188B4 00000043 */  sra       $zero, $zero, 1
/* 4CFA68 802188B8 00000004 */  sllv      $zero, $zero, $zero
/* 4CFA6C 802188BC 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CFA70 802188C0 00000000 */  nop       
/* 4CFA74 802188C4 00000000 */  nop       
/* 4CFA78 802188C8 00010002 */  srl       $zero, $at, 0
/* 4CFA7C 802188CC 00000043 */  sra       $zero, $zero, 1
/* 4CFA80 802188D0 00000006 */  srlv      $zero, $zero, $zero
/* 4CFA84 802188D4 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CFA88 802188D8 000C0118 */  .byte     0x00, 0x0c, 0x01, 0x18
/* 4CFA8C 802188DC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFA90 802188E0 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFA94 802188E4 00120002 */  srl       $zero, $s2, 0
/* 4CFA98 802188E8 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CFA9C 802188EC 00000008 */  jr        $zero
/* 4CFAA0 802188F0 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802188F4_4CFAA4
/* 4CFAA4 802188F4 0000000A */  movz      $zero, $zero, $zero
/* 4CFAA8 802188F8 00000043 */  sra       $zero, $zero, 1
/* 4CFAAC 802188FC 00000002 */  srl       $zero, $zero, 0
/* 4CFAB0 80218900 8026E16C */  lb        $a2, -0x1e94($at)
/* 4CFAB4 80218904 00000006 */  srlv      $zero, $zero, $zero
/* 4CFAB8 80218908 00000043 */  sra       $zero, $zero, 1
/* 4CFABC 8021890C 00000002 */  srl       $zero, $zero, 0
/* 4CFAC0 80218910 8026E198 */  lb        $a2, -0x1e68($at)
/* 4CFAC4 80218914 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFAC8 80218918 00000008 */  jr        $zero
/* 4CFACC 8021891C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218920_4CFAD0
/* 4CFAD0 80218920 00000014 */  dsllv     $zero, $zero, $zero
/* 4CFAD4 80218924 00000043 */  sra       $zero, $zero, 1
/* 4CFAD8 80218928 00000006 */  srlv      $zero, $zero, $zero
/* 4CFADC 8021892C 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CFAE0 80218930 000C0119 */  .byte     0x00, 0x0c, 0x01, 0x19
/* 4CFAE4 80218934 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFAE8 80218938 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFAEC 8021893C 00120002 */  srl       $zero, $s2, 0
/* 4CFAF0 80218940 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CFAF4 80218944 00000008 */  jr        $zero
/* 4CFAF8 80218948 00000001 */   movf     $zero, $zero, $fcc0

glabel func_8021894C_4CFAFC
/* 4CFAFC 8021894C 0000000A */  movz      $zero, $zero, $zero
/* 4CFB00 80218950 00000043 */  sra       $zero, $zero, 1
/* 4CFB04 80218954 00000003 */  sra       $zero, $zero, 0
/* 4CFB08 80218958 8026F0EC */  lb        $a2, -0xf14($at)
/* 4CFB0C 8021895C 00000000 */  nop       
/* 4CFB10 80218960 00000000 */  nop       
/* 4CFB14 80218964 00000056 */  drotrv    $zero, $zero, $zero
/* 4CFB18 80218968 00000000 */  nop       
/* 4CFB1C 8021896C 00000043 */  sra       $zero, $zero, 1
/* 4CFB20 80218970 00000003 */  sra       $zero, $zero, 0
/* 4CFB24 80218974 8027D57C */  lb        $a3, -0x2a84($at)
/* 4CFB28 80218978 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFB2C 8021897C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFB30 80218980 00000043 */  sra       $zero, $zero, 1
/* 4CFB34 80218984 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFB38 80218988 8026A510 */  lb        $a2, -0x5af0($at)
/* 4CFB3C 8021898C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFB40 80218990 FFFFFF92 */  sd        $ra, -0x6e($ra)
/* 4CFB44 80218994 00000064 */  .byte     0x00, 0x00, 0x00, 0x64
/* 4CFB48 80218998 00000000 */  nop       
/* 4CFB4C 8021899C 00000043 */  sra       $zero, $zero, 1
/* 4CFB50 802189A0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFB54 802189A4 8027B624 */  lb        $a3, -0x49dc($at)
/* 4CFB58 802189A8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFB5C 802189AC 00000014 */  dsllv     $zero, $zero, $zero
/* 4CFB60 802189B0 00000000 */  nop       
/* 4CFB64 802189B4 0000000A */  movz      $zero, $zero, $zero
/* 4CFB68 802189B8 00000043 */  sra       $zero, $zero, 1
/* 4CFB6C 802189BC 00000003 */  sra       $zero, $zero, 0
/* 4CFB70 802189C0 8027D57C */  lb        $a3, -0x2a84($at)
/* 4CFB74 802189C4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFB78 802189C8 00000000 */  nop       
/* 4CFB7C 802189CC 00000043 */  sra       $zero, $zero, 1
/* 4CFB80 802189D0 00000004 */  sllv      $zero, $zero, $zero
/* 4CFB84 802189D4 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CFB88 802189D8 00000000 */  nop       
/* 4CFB8C 802189DC 00000000 */  nop       
/* 4CFB90 802189E0 0001002A */  slt       $zero, $zero, $at
/* 4CFB94 802189E4 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4CFB98 802189E8 00000000 */  nop       
/* 4CFB9C 802189EC 00000008 */  jr        $zero
/* 4CFBA0 802189F0 00000001 */   movf     $zero, $zero, $fcc0

glabel func_802189F4_4CFBA4
/* 4CFBA4 802189F4 0000000A */  movz      $zero, $zero, $zero
/* 4CFBA8 802189F8 00000043 */  sra       $zero, $zero, 1
/* 4CFBAC 802189FC 00000004 */  sllv      $zero, $zero, $zero
/* 4CFBB0 80218A00 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CFBB4 80218A04 00000000 */  nop       
/* 4CFBB8 80218A08 00000000 */  nop       
/* 4CFBBC 80218A0C 0001002A */  slt       $zero, $zero, $at
/* 4CFBC0 80218A10 00000043 */  sra       $zero, $zero, 1
/* 4CFBC4 80218A14 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFBC8 80218A18 802180C8 */  lb        $at, -0x7f38($at)
/* 4CFBCC 80218A1C 00000008 */  jr        $zero
/* 4CFBD0 80218A20 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218A24_4CFBD4
/* 4CFBD4 80218A24 00000078 */  dsll      $zero, $zero, 1
/* 4CFBD8 80218A28 00000043 */  sra       $zero, $zero, 1
/* 4CFBDC 80218A2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFBE0 80218A30 802180E8 */  lb        $at, -0x7f18($at)
/* 4CFBE4 80218A34 00000043 */  sra       $zero, $zero, 1
/* 4CFBE8 80218A38 00000004 */  sllv      $zero, $zero, $zero
/* 4CFBEC 80218A3C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CFBF0 80218A40 00000000 */  nop       
/* 4CFBF4 80218A44 00000000 */  nop       
/* 4CFBF8 80218A48 00010002 */  srl       $zero, $at, 0
/* 4CFBFC 80218A4C 00000043 */  sra       $zero, $zero, 1
/* 4CFC00 80218A50 00000004 */  sllv      $zero, $zero, $zero
/* 4CFC04 80218A54 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CFC08 80218A58 00000000 */  nop       
/* 4CFC0C 80218A5C 00000000 */  nop       
/* 4CFC10 80218A60 00010002 */  srl       $zero, $at, 0
/* 4CFC14 80218A64 00000043 */  sra       $zero, $zero, 1
/* 4CFC18 80218A68 00000002 */  srl       $zero, $zero, 0
/* 4CFC1C 80218A6C 80269EC4 */  lb        $a2, -0x613c($at)
/* 4CFC20 80218A70 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFC24 80218A74 00000043 */  sra       $zero, $zero, 1
/* 4CFC28 80218A78 00000003 */  sra       $zero, $zero, 0
/* 4CFC2C 80218A7C 8027D57C */  lb        $a3, -0x2a84($at)
/* 4CFC30 80218A80 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFC34 80218A84 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFC38 80218A88 00000043 */  sra       $zero, $zero, 1
/* 4CFC3C 80218A8C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFC40 80218A90 8027B624 */  lb        $a3, -0x49dc($at)
/* 4CFC44 80218A94 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFC48 80218A98 00000014 */  dsllv     $zero, $zero, $zero
/* 4CFC4C 80218A9C 00000000 */  nop       
/* 4CFC50 80218AA0 0000000A */  movz      $zero, $zero, $zero
/* 4CFC54 80218AA4 00000043 */  sra       $zero, $zero, 1
/* 4CFC58 80218AA8 00000003 */  sra       $zero, $zero, 0
/* 4CFC5C 80218AAC 8027D57C */  lb        $a3, -0x2a84($at)
/* 4CFC60 80218AB0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFC64 80218AB4 00000000 */  nop       
/* 4CFC68 80218AB8 00000043 */  sra       $zero, $zero, 1
/* 4CFC6C 80218ABC 00000006 */  srlv      $zero, $zero, $zero
/* 4CFC70 80218AC0 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CFC74 80218AC4 000C011A */  .byte     0x00, 0x0c, 0x01, 0x1a
/* 4CFC78 80218AC8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFC7C 80218ACC 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFC80 80218AD0 00120002 */  srl       $zero, $s2, 0
/* 4CFC84 80218AD4 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CFC88 80218AD8 00000008 */  jr        $zero
/* 4CFC8C 80218ADC 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218AE0_4CFC90
/* 4CFC90 80218AE0 0000000A */  movz      $zero, $zero, $zero
/* 4CFC94 80218AE4 00000043 */  sra       $zero, $zero, 1
/* 4CFC98 80218AE8 00000006 */  srlv      $zero, $zero, $zero
/* 4CFC9C 80218AEC 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CFCA0 80218AF0 000C011B */  .byte     0x00, 0x0c, 0x01, 0x1b
/* 4CFCA4 80218AF4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFCA8 80218AF8 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFCAC 80218AFC 00120002 */  srl       $zero, $s2, 0
/* 4CFCB0 80218B00 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CFCB4 80218B04 00000008 */  jr        $zero
/* 4CFCB8 80218B08 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218B0C_4CFCBC
/* 4CFCBC 80218B0C 0000000A */  movz      $zero, $zero, $zero
/* 4CFCC0 80218B10 00000043 */  sra       $zero, $zero, 1
/* 4CFCC4 80218B14 00000002 */  srl       $zero, $zero, 0
/* 4CFCC8 80218B18 8026E020 */  lb        $a2, -0x1fe0($at)
/* 4CFCCC 80218B1C 00000100 */  sll       $zero, $zero, 4
/* 4CFCD0 80218B20 00000043 */  sra       $zero, $zero, 1
/* 4CFCD4 80218B24 00000002 */  srl       $zero, $zero, 0
/* 4CFCD8 80218B28 8026E038 */  lb        $a2, -0x1fc8($at)
/* 4CFCDC 80218B2C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFCE0 80218B30 00000043 */  sra       $zero, $zero, 1
/* 4CFCE4 80218B34 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFCE8 80218B38 80218158 */  lb        $at, -0x7ea8($at)
/* 4CFCEC 80218B3C 00000043 */  sra       $zero, $zero, 1
/* 4CFCF0 80218B40 00000002 */  srl       $zero, $zero, 0
/* 4CFCF4 80218B44 8026E198 */  lb        $a2, -0x1e68($at)
/* 4CFCF8 80218B48 00000012 */  mflo      $zero
/* 4CFCFC 80218B4C 00000024 */  and       $zero, $zero, $zero
/* 4CFD00 80218B50 00000002 */  srl       $zero, $zero, 0
/* 4CFD04 80218B54 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFD08 80218B58 000000FF */  dsra32    $zero, $zero, 3
/* 4CFD0C 80218B5C 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFD10 80218B60 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFD14 80218B64 0000000A */  movz      $zero, $zero, $zero
/* 4CFD18 80218B68 00000028 */  .byte     0x00, 0x00, 0x00, 0x28
/* 4CFD1C 80218B6C 00000002 */  srl       $zero, $zero, 0
/* 4CFD20 80218B70 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFD24 80218B74 00000019 */  multu     $zero, $zero
/* 4CFD28 80218B78 0000000C */  syscall   
/* 4CFD2C 80218B7C 00000002 */  srl       $zero, $zero, 0
/* 4CFD30 80218B80 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFD34 80218B84 00000000 */  nop       
/* 4CFD38 80218B88 00000024 */  and       $zero, $zero, $zero
/* 4CFD3C 80218B8C 00000002 */  srl       $zero, $zero, 0
/* 4CFD40 80218B90 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFD44 80218B94 00000000 */  nop       
/* 4CFD48 80218B98 00000013 */  mtlo      $zero
/* 4CFD4C 80218B9C 00000000 */  nop       
/* 4CFD50 80218BA0 00000043 */  sra       $zero, $zero, 1
/* 4CFD54 80218BA4 00000004 */  sllv      $zero, $zero, $zero
/* 4CFD58 80218BA8 8026F470 */  lb        $a2, -0xb90($at)
/* 4CFD5C 80218BAC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFD60 80218BB0 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFD64 80218BB4 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFD68 80218BB8 00000008 */  jr        $zero
/* 4CFD6C 80218BBC 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218BC0_4CFD70
/* 4CFD70 80218BC0 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFD74 80218BC4 00000006 */  srlv      $zero, $zero, $zero
/* 4CFD78 80218BC8 00000000 */  nop       
/* 4CFD7C 80218BCC 00000043 */  sra       $zero, $zero, 1
/* 4CFD80 80218BD0 00000004 */  sllv      $zero, $zero, $zero
/* 4CFD84 80218BD4 8026F470 */  lb        $a2, -0xb90($at)
/* 4CFD88 80218BD8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFD8C 80218BDC 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFD90 80218BE0 00000000 */  nop       
/* 4CFD94 80218BE4 00000043 */  sra       $zero, $zero, 1
/* 4CFD98 80218BE8 00000004 */  sllv      $zero, $zero, $zero
/* 4CFD9C 80218BEC 8026CE8C */  lb        $a2, -0x3174($at)
/* 4CFDA0 80218BF0 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFDA4 80218BF4 00000004 */  sllv      $zero, $zero, $zero
/* 4CFDA8 80218BF8 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFDAC 80218BFC 00000056 */  drotrv    $zero, $zero, $zero
/* 4CFDB0 80218C00 00000000 */  nop       
/* 4CFDB4 80218C04 00000043 */  sra       $zero, $zero, 1
/* 4CFDB8 80218C08 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFDBC 80218C0C 80218170 */  lb        $at, -0x7e90($at)
/* 4CFDC0 80218C10 00000057 */  .byte     0x00, 0x00, 0x00, 0x57
/* 4CFDC4 80218C14 00000000 */  nop       
/* 4CFDC8 80218C18 00000043 */  sra       $zero, $zero, 1
/* 4CFDCC 80218C1C 00000002 */  srl       $zero, $zero, 0
/* 4CFDD0 80218C20 8026E198 */  lb        $a2, -0x1e68($at)
/* 4CFDD4 80218C24 00000016 */  dsrlv     $zero, $zero, $zero
/* 4CFDD8 80218C28 00000024 */  and       $zero, $zero, $zero
/* 4CFDDC 80218C2C 00000002 */  srl       $zero, $zero, 0
/* 4CFDE0 80218C30 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFDE4 80218C34 00000000 */  nop       
/* 4CFDE8 80218C38 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFDEC 80218C3C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFDF0 80218C40 0000000A */  movz      $zero, $zero, $zero
/* 4CFDF4 80218C44 00000027 */  not       $zero, $zero
/* 4CFDF8 80218C48 00000002 */  srl       $zero, $zero, 0
/* 4CFDFC 80218C4C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFE00 80218C50 00000019 */  multu     $zero, $zero
/* 4CFE04 80218C54 0000000D */  break     
/* 4CFE08 80218C58 00000002 */   srl      $zero, $zero, 0
/* 4CFE0C 80218C5C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFE10 80218C60 000000FF */  dsra32    $zero, $zero, 3
/* 4CFE14 80218C64 00000024 */  and       $zero, $zero, $zero
/* 4CFE18 80218C68 00000002 */  srl       $zero, $zero, 0
/* 4CFE1C 80218C6C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFE20 80218C70 000000FF */  dsra32    $zero, $zero, 3
/* 4CFE24 80218C74 00000013 */  mtlo      $zero
/* 4CFE28 80218C78 00000000 */  nop       
/* 4CFE2C 80218C7C 00000043 */  sra       $zero, $zero, 1
/* 4CFE30 80218C80 00000004 */  sllv      $zero, $zero, $zero
/* 4CFE34 80218C84 8026F470 */  lb        $a2, -0xb90($at)
/* 4CFE38 80218C88 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFE3C 80218C8C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFE40 80218C90 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFE44 80218C94 00000008 */  jr        $zero
/* 4CFE48 80218C98 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218C9C_4CFE4C
/* 4CFE4C 80218C9C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFE50 80218CA0 00000006 */  srlv      $zero, $zero, $zero
/* 4CFE54 80218CA4 00000000 */  nop       
/* 4CFE58 80218CA8 00000043 */  sra       $zero, $zero, 1
/* 4CFE5C 80218CAC 00000004 */  sllv      $zero, $zero, $zero
/* 4CFE60 80218CB0 8026F470 */  lb        $a2, -0xb90($at)
/* 4CFE64 80218CB4 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFE68 80218CB8 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFE6C 80218CBC 000000FF */  dsra32    $zero, $zero, 3
/* 4CFE70 80218CC0 00000043 */  sra       $zero, $zero, 1
/* 4CFE74 80218CC4 00000004 */  sllv      $zero, $zero, $zero
/* 4CFE78 80218CC8 8026CE8C */  lb        $a2, -0x3174($at)
/* 4CFE7C 80218CCC FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFE80 80218CD0 00000004 */  sllv      $zero, $zero, $zero
/* 4CFE84 80218CD4 00000000 */  nop       
/* 4CFE88 80218CD8 00000043 */  sra       $zero, $zero, 1
/* 4CFE8C 80218CDC 00000006 */  srlv      $zero, $zero, $zero
/* 4CFE90 80218CE0 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CFE94 80218CE4 000C011C */  .byte     0x00, 0x0c, 0x01, 0x1c
/* 4CFE98 80218CE8 FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFE9C 80218CEC 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFEA0 80218CF0 00120002 */  srl       $zero, $s2, 0
/* 4CFEA4 80218CF4 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CFEA8 80218CF8 00000008 */  jr        $zero
/* 4CFEAC 80218CFC 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218D00_4CFEB0
/* 4CFEB0 80218D00 0000000A */  movz      $zero, $zero, $zero
/* 4CFEB4 80218D04 00000043 */  sra       $zero, $zero, 1
/* 4CFEB8 80218D08 00000003 */  sra       $zero, $zero, 0
/* 4CFEBC 80218D0C 8026F0EC */  lb        $a2, -0xf14($at)
/* 4CFEC0 80218D10 00000000 */  nop       
/* 4CFEC4 80218D14 00000000 */  nop       
/* 4CFEC8 80218D18 00000043 */  sra       $zero, $zero, 1
/* 4CFECC 80218D1C 00000004 */  sllv      $zero, $zero, $zero
/* 4CFED0 80218D20 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CFED4 80218D24 00000000 */  nop       
/* 4CFED8 80218D28 00000000 */  nop       
/* 4CFEDC 80218D2C 0001002A */  slt       $zero, $zero, $at
/* 4CFEE0 80218D30 00000043 */  sra       $zero, $zero, 1
/* 4CFEE4 80218D34 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFEE8 80218D38 802180C8 */  lb        $at, -0x7f38($at)
/* 4CFEEC 80218D3C 00000008 */  jr        $zero
/* 4CFEF0 80218D40 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218D44_4CFEF4
/* 4CFEF4 80218D44 00000078 */  dsll      $zero, $zero, 1
/* 4CFEF8 80218D48 00000043 */  sra       $zero, $zero, 1
/* 4CFEFC 80218D4C 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFF00 80218D50 802180E8 */  lb        $at, -0x7f18($at)
/* 4CFF04 80218D54 00000043 */  sra       $zero, $zero, 1
/* 4CFF08 80218D58 00000004 */  sllv      $zero, $zero, $zero
/* 4CFF0C 80218D5C 8026B1B0 */  lb        $a2, -0x4e50($at)
/* 4CFF10 80218D60 00000000 */  nop       
/* 4CFF14 80218D64 00000000 */  nop       
/* 4CFF18 80218D68 00010002 */  srl       $zero, $at, 0
/* 4CFF1C 80218D6C 00000043 */  sra       $zero, $zero, 1
/* 4CFF20 80218D70 00000006 */  srlv      $zero, $zero, $zero
/* 4CFF24 80218D74 80252F30 */  lb        $a1, 0x2f30($at)
/* 4CFF28 80218D78 000C011D */  .byte     0x00, 0x0c, 0x01, 0x1d
/* 4CFF2C 80218D7C FFFFFF81 */  sd        $ra, -0x7f($ra)
/* 4CFF30 80218D80 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFF34 80218D84 00120002 */  srl       $zero, $s2, 0
/* 4CFF38 80218D88 00120001 */  .byte     0x00, 0x12, 0x00, 0x01
/* 4CFF3C 80218D8C 00000043 */  sra       $zero, $zero, 1
/* 4CFF40 80218D90 00000002 */  srl       $zero, $zero, 0
/* 4CFF44 80218D94 8026E198 */  lb        $a2, -0x1e68($at)
/* 4CFF48 80218D98 00000000 */  nop       
/* 4CFF4C 80218D9C 00000043 */  sra       $zero, $zero, 1
/* 4CFF50 80218DA0 00000002 */  srl       $zero, $zero, 0
/* 4CFF54 80218DA4 8026E16C */  lb        $a2, -0x1e94($at)
/* 4CFF58 80218DA8 0000001E */  ddiv      $zero, $zero, $zero
/* 4CFF5C 80218DAC 00000008 */  jr        $zero
/* 4CFF60 80218DB0 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218DB4_4CFF64
/* 4CFF64 80218DB4 00002710 */  .byte     0x00, 0x00, 0x27, 0x10
/* 4CFF68 80218DB8 00000002 */  srl       $zero, $zero, 0
/* 4CFF6C 80218DBC 00000000 */  nop       
/* 4CFF70 80218DC0 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFF74 80218DC4 00000000 */  nop       
/* 4CFF78 80218DC8 00000000 */  nop       
/* 4CFF7C 80218DCC 00000000 */  nop       
/* 4CFF80 80218DD0 00000024 */  and       $zero, $zero, $zero
/* 4CFF84 80218DD4 00000002 */  srl       $zero, $zero, 0
/* 4CFF88 80218DD8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4CFF8C 80218DDC FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4CFF90 80218DE0 00000003 */  sra       $zero, $zero, 0
/* 4CFF94 80218DE4 00000001 */  movf      $zero, $zero, $fcc0
/* 4CFF98 80218DE8 00000000 */  nop       
/* 4CFF9C 80218DEC 00000043 */  sra       $zero, $zero, 1
/* 4CFFA0 80218DF0 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFFA4 80218DF4 802C8B60 */  lb        $t4, -0x74a0($at)
/* 4CFFA8 80218DF8 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4CFFAC 80218DFC 00000000 */  nop       
/* 4CFFB0 80218E00 00000002 */  srl       $zero, $zero, 0
/* 4CFFB4 80218E04 00000000 */  nop       
/* 4CFFB8 80218E08 00000008 */  jr        $zero
/* 4CFFBC 80218E0C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218E10_4CFFC0
/* 4CFFC0 80218E10 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFFC4 80218E14 00000043 */  sra       $zero, $zero, 1
/* 4CFFC8 80218E18 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFFCC 80218E1C 802C8B60 */  lb        $t4, -0x74a0($at)
/* 4CFFD0 80218E20 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4CFFD4 80218E24 00000000 */  nop       
/* 4CFFD8 80218E28 00000000 */  nop       
/* 4CFFDC 80218E2C 00000000 */  nop       
/* 4CFFE0 80218E30 00000008 */  jr        $zero
/* 4CFFE4 80218E34 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218E38_4CFFE8
/* 4CFFE8 80218E38 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFFEC 80218E3C 00000043 */  sra       $zero, $zero, 1
/* 4CFFF0 80218E40 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4CFFF4 80218E44 802C8B60 */  lb        $t4, -0x74a0($at)
/* 4CFFF8 80218E48 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4CFFFC 80218E4C 00000000 */  nop       
/* 4D0000 80218E50 00000002 */  srl       $zero, $zero, 0
/* 4D0004 80218E54 00000000 */  nop       
/* 4D0008 80218E58 00000008 */  jr        $zero
/* 4D000C 80218E5C 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218E60_4D0010
/* 4D0010 80218E60 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4D0014 80218E64 00000043 */  sra       $zero, $zero, 1
/* 4D0018 80218E68 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4D001C 80218E6C 802C8B60 */  lb        $t4, -0x74a0($at)
/* 4D0020 80218E70 FE363C8A */  sd        $s6, 0x3c8a($s1)
/* 4D0024 80218E74 00000000 */  nop       
/* 4D0028 80218E78 00000000 */  nop       
/* 4D002C 80218E7C 00000000 */  nop       
/* 4D0030 80218E80 00000008 */  jr        $zero
/* 4D0034 80218E84 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218E88_4D0038
/* 4D0038 80218E88 00000005 */  lsa       $zero, $zero, $zero, 1
/* 4D003C 80218E8C 00000043 */  sra       $zero, $zero, 1
/* 4D0040 80218E90 00000003 */  sra       $zero, $zero, 0
/* 4D0044 80218E94 802D46B0 */  lb        $t5, 0x46b0($at)
/* 4D0048 80218E98 0000001E */  ddiv      $zero, $zero, $zero
/* 4D004C 80218E9C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D0050 80218EA0 00000027 */  not       $zero, $zero
/* 4D0054 80218EA4 00000002 */  srl       $zero, $zero, 0
/* 4D0058 80218EA8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D005C 80218EAC 0000001E */  ddiv      $zero, $zero, $zero
/* 4D0060 80218EB0 00000008 */  jr        $zero
/* 4D0064 80218EB4 00000001 */   movf     $zero, $zero, $fcc0

glabel func_80218EB8_4D0068
/* 4D0068 80218EB8 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D006C 80218EBC 00000004 */  sllv      $zero, $zero, $zero
/* 4D0070 80218EC0 00000001 */  movf      $zero, $zero, $fcc0
/* 4D0074 80218EC4 00000000 */  nop       
/* 4D0078 80218EC8 00000002 */  srl       $zero, $zero, 0
/* 4D007C 80218ECC 00000000 */  nop       
/* 4D0080 80218ED0 00000001 */  movf      $zero, $zero, $fcc0
/* 4D0084 80218ED4 00000000 */  nop       
/* 4D0088 80218ED8 00000043 */  sra       $zero, $zero, 1
/* 4D008C 80218EDC 00000002 */  srl       $zero, $zero, 0
/* 4D0090 80218EE0 802D9700 */  lb        $t5, -0x6900($at)
/* 4D0094 80218EE4 FFFFFFFF */  sd        $ra, -1($ra)
/* 4D0098 80218EE8 00000024 */  and       $zero, $zero, $zero
/* 4D009C 80218EEC 00000002 */  srl       $zero, $zero, 0
/* 4D00A0 80218EF0 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D00A4 80218EF4 00000013 */  mtlo      $zero
/* 4D00A8 80218EF8 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4D00AC 80218EFC 00000001 */  movf      $zero, $zero, $fcc0
/* 4D00B0 80218F00 80218DD0 */  lb        $at, -0x7230($at)
/* 4D00B4 80218F04 00000024 */  and       $zero, $zero, $zero
/* 4D00B8 80218F08 00000002 */  srl       $zero, $zero, 0
/* 4D00BC 80218F0C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D00C0 80218F10 00000014 */  dsllv     $zero, $zero, $zero
/* 4D00C4 80218F14 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4D00C8 80218F18 00000001 */  movf      $zero, $zero, $fcc0
/* 4D00CC 80218F1C 80218DD0 */  lb        $at, -0x7230($at)
/* 4D00D0 80218F20 00000024 */  and       $zero, $zero, $zero
/* 4D00D4 80218F24 00000002 */  srl       $zero, $zero, 0
/* 4D00D8 80218F28 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D00DC 80218F2C 00000015 */  dlsa      $zero, $zero, $zero, 1
/* 4D00E0 80218F30 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4D00E4 80218F34 00000001 */  movf      $zero, $zero, $fcc0
/* 4D00E8 80218F38 80218DD0 */  lb        $at, -0x7230($at)
/* 4D00EC 80218F3C 00000024 */  and       $zero, $zero, $zero
/* 4D00F0 80218F40 00000002 */  srl       $zero, $zero, 0
/* 4D00F4 80218F44 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D00F8 80218F48 00000016 */  dsrlv     $zero, $zero, $zero
/* 4D00FC 80218F4C 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4D0100 80218F50 00000001 */  movf      $zero, $zero, $fcc0
/* 4D0104 80218F54 80218DD0 */  lb        $at, -0x7230($at)
/* 4D0108 80218F58 00000024 */  and       $zero, $zero, $zero
/* 4D010C 80218F5C 00000002 */  srl       $zero, $zero, 0
/* 4D0110 80218F60 FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D0114 80218F64 00000017 */  dsrav     $zero, $zero, $zero
/* 4D0118 80218F68 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4D011C 80218F6C 00000001 */  movf      $zero, $zero, $fcc0
/* 4D0120 80218F70 80218DD0 */  lb        $at, -0x7230($at)
/* 4D0124 80218F74 00000024 */  and       $zero, $zero, $zero
/* 4D0128 80218F78 00000002 */  srl       $zero, $zero, 0
/* 4D012C 80218F7C FE363C80 */  sd        $s6, 0x3c80($s1)
/* 4D0130 80218F80 00000018 */  mult      $zero, $zero
/* 4D0134 80218F84 00000044 */  .byte     0x00, 0x00, 0x00, 0x44
/* 4D0138 80218F88 00000001 */  movf      $zero, $zero, $fcc0
/* 4D013C 80218F8C 80218DD0 */  lb        $at, -0x7230($at)
/* 4D0140 80218F90 00000002 */  srl       $zero, $zero, 0
/* 4D0144 80218F94 00000000 */  nop       
/* 4D0148 80218F98 00000001 */  movf      $zero, $zero, $fcc0
/* 4D014C 80218F9C 00000000 */  nop       
/* 4D0150 80218FA0 00000002 */  srl       $zero, $zero, 0
/* 4D0154 80218FA4 00000000 */  nop       
/* 4D0158 80218FA8 00000001 */  movf      $zero, $zero, $fcc0
/* 4D015C 80218FAC 00000000 */  nop       
/* 4D0160 80218FB0 0000001E */  ddiv      $zero, $zero, $zero
/* 4D0164 80218FB4 0000001D */  dmultu    $zero, $zero
/* 4D0168 80218FB8 0000001C */  dmult     $zero, $zero
/* 4D016C 80218FBC 00000000 */  nop       
/* 4D0170 80218FC0 80219038 */  lb        $at, -0x6fc8($at)
/* 4D0174 80218FC4 80219028 */  lb        $at, -0x6fd8($at)
/* 4D0178 80218FC8 80219018 */  lb        $at, -0x6fe8($at)
/* 4D017C 80218FCC 80218ED8 */  lb        $at, -0x7128($at)
/* 4D0180 80218FD0 80218FA0 */  lb        $at, -0x7060($at)
/* 4D0184 80218FD4 80219010 */  lb        $at, -0x6ff0($at)
/* 4D0188 80218FD8 80218FB0 */  lb        $at, -0x7050($at)
/* 4D018C 80218FDC 00000000 */  nop       
/* 4D0190 80218FE0 00000000 */  nop       
/* 4D0194 80218FE4 00000000 */  nop       
/* 4D0198 80218FE8 00000000 */  nop       
/* 4D019C 80218FEC 00000000 */  nop       
/* 4D01A0 80218FF0 82D982B5 */  lb        $t9, -0x7d4b($s6)
/* 4D01A4 80218FF4 82CC82B9 */  lb        $t4, -0x7d47($s6)
/* 4D01A8 80218FF8 82A22083 */  lb        $v0, 0x2083($s5)
/* 4D01AC 80218FFC 8C834E83 */  lw        $v1, 0x4e83($a0)
/* 4D01B0 80219000 60838381 */  daddi     $v1, $a0, -0x7c7f
/* 4D01B4 80219004 5B000000 */  blezl     $t8, .L80219008
.L80219008:
/* 4D01B8 80219008 6E6F6B5F */   ldr      $t7, 0x6b5f($s3)
/* 4D01BC 8021900C 30310000 */  andi      $s1, $at, 0
/* 4D01C0 80219010 6E6F6B5F */  ldr       $t7, 0x6b5f($s3)
/* 4D01C4 80219014 62670000 */  daddi     $a3, $s3, 0
/* 4D01C8 80219018 6E6F6B5F */  ldr       $t7, 0x6b5f($s3)
/* 4D01CC 8021901C 62743031 */  daddi     $s4, $s3, 0x3031
/* 4D01D0 80219020 5F686974 */  .byte     0x5f, 0x68, 0x69, 0x74
/* 4D01D4 80219024 00000000 */  nop       
/* 4D01D8 80219028 6E6F6B5F */  ldr       $t7, 0x6b5f($s3)
/* 4D01DC 8021902C 62743031 */  daddi     $s4, $s3, 0x3031
/* 4D01E0 80219030 5F736861 */  .byte     0x5f, 0x73, 0x68, 0x61
/* 4D01E4 80219034 70650000 */  madd      $v1, $a1
/* 4D01E8 80219038 6E6F6B5F */  ldr       $t7, 0x6b5f($s3)
/* 4D01EC 8021903C 74657800 */  jalx      0x8195e000
