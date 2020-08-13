.set noat # allow manual use of $at
.set noreorder # don't insert nops after branches

.include "include/macro.inc"

glabel func_80147AC4
/* 0DE1C4 80147AC4 27BDFED0 */  addiu $sp, $sp, -0x130
/* 0DE1C8 80147AC8 27A20020 */  addiu $v0, $sp, 0x20
/* 0DE1CC 80147ACC 2404FFFF */  addiu $a0, $zero, -1
/* 0DE1D0 80147AD0 2403003F */  addiu $v1, $zero, 0x3f
/* 0DE1D4 80147AD4 AFBF012C */  sw    $ra, 0x12c($sp)
/* 0DE1D8 80147AD8 AFB20128 */  sw    $s2, 0x128($sp)
/* 0DE1DC 80147ADC AFB10124 */  sw    $s1, 0x124($sp)
/* 0DE1E0 80147AE0 AFB00120 */  sw    $s0, 0x120($sp)
.L80147AE4:
/* 0DE1E4 80147AE4 AC440000 */  sw    $a0, ($v0)
/* 0DE1E8 80147AE8 2463FFFF */  addiu $v1, $v1, -1
/* 0DE1EC 80147AEC 0461FFFD */  bgez  $v1, .L80147AE4
/* 0DE1F0 80147AF0 24420004 */   addiu $v0, $v0, 4
/* 0DE1F4 80147AF4 0000182D */  daddu $v1, $zero, $zero
/* 0DE1F8 80147AF8 3C048016 */  lui   $a0, 0x8016
/* 0DE1FC 80147AFC 24849D50 */  addiu $a0, $a0, -0x62b0
/* 0DE200 80147B00 27A50020 */  addiu $a1, $sp, 0x20
.L80147B04:
/* 0DE204 80147B04 90820000 */  lbu   $v0, ($a0)
/* 0DE208 80147B08 50400006 */  beql  $v0, $zero, .L80147B24
/* 0DE20C 80147B0C 24630001 */   addiu $v1, $v1, 1
/* 0DE210 80147B10 90820001 */  lbu   $v0, 1($a0)
/* 0DE214 80147B14 00021080 */  sll   $v0, $v0, 2
/* 0DE218 80147B18 00A21021 */  addu  $v0, $a1, $v0
/* 0DE21C 80147B1C AC430000 */  sw    $v1, ($v0)
/* 0DE220 80147B20 24630001 */  addiu $v1, $v1, 1
.L80147B24:
/* 0DE224 80147B24 28620040 */  slti  $v0, $v1, 0x40
/* 0DE228 80147B28 1440FFF6 */  bnez  $v0, .L80147B04
/* 0DE22C 80147B2C 24840020 */   addiu $a0, $a0, 0x20
/* 0DE230 80147B30 3C06D9FF */  lui   $a2, 0xd9ff
/* 0DE234 80147B34 34C6FFFF */  ori   $a2, $a2, 0xffff
/* 0DE238 80147B38 3C050020 */  lui   $a1, 0x20
/* 0DE23C 80147B3C 34A50605 */  ori   $a1, $a1, 0x605
/* 0DE240 80147B40 3C07E300 */  lui   $a3, 0xe300
/* 0DE244 80147B44 34E70800 */  ori   $a3, $a3, 0x800
/* 0DE248 80147B48 3C09FCFF */  lui   $t1, 0xfcff
/* 0DE24C 80147B4C 3529FFFF */  ori   $t1, $t1, 0xffff
/* 0DE250 80147B50 3C08FFFE */  lui   $t0, 0xfffe
/* 0DE254 80147B54 3508793C */  ori   $t0, $t0, 0x793c
/* 0DE258 80147B58 3C0AE200 */  lui   $t2, 0xe200
/* 0DE25C 80147B5C 354A1E01 */  ori   $t2, $t2, 0x1e01
/* 0DE260 80147B60 3C0BE300 */  lui   $t3, 0xe300
/* 0DE264 80147B64 356B0C0F */  ori   $t3, $t3, 0xc0f
/* 0DE268 80147B68 3C0CDB04 */  lui   $t4, 0xdb04
/* 0DE26C 80147B6C 358C0004 */  ori   $t4, $t4, 4
/* 0DE270 80147B70 3C0DDB04 */  lui   $t5, 0xdb04
/* 0DE274 80147B74 35AD000C */  ori   $t5, $t5, 0xc
/* 0DE278 80147B78 3C0EDB04 */  lui   $t6, 0xdb04
/* 0DE27C 80147B7C 35CE0014 */  ori   $t6, $t6, 0x14
/* 0DE280 80147B80 3C0FDB04 */  lui   $t7, 0xdb04
/* 0DE284 80147B84 35EF001C */  ori   $t7, $t7, 0x1c
/* 0DE288 80147B88 3C12FF10 */  lui   $s2, 0xff10
/* 0DE28C 80147B8C 3652013F */  ori   $s2, $s2, 0x13f
/* 0DE290 80147B90 3C11800A */  lui   $s1, 0x800a
/* 0DE294 80147B94 2631A66C */  addiu $s1, $s1, -0x5994
/* 0DE298 80147B98 3C02D900 */  lui   $v0, 0xd900
/* 0DE29C 80147B9C 8E300000 */  lw    $s0, ($s1)
/* 0DE2A0 80147BA0 3C04800A */  lui   $a0, 0x800a
/* 0DE2A4 80147BA4 8C84A64C */  lw    $a0, -0x59b4($a0)
/* 0DE2A8 80147BA8 0200182D */  daddu $v1, $s0, $zero
/* 0DE2AC 80147BAC 26100008 */  addiu $s0, $s0, 8
/* 0DE2B0 80147BB0 AE300000 */  sw    $s0, ($s1)
/* 0DE2B4 80147BB4 AC620000 */  sw    $v0, ($v1)
/* 0DE2B8 80147BB8 26020008 */  addiu $v0, $s0, 8
/* 0DE2BC 80147BBC AC600004 */  sw    $zero, 4($v1)
/* 0DE2C0 80147BC0 AE220000 */  sw    $v0, ($s1)
/* 0DE2C4 80147BC4 26020010 */  addiu $v0, $s0, 0x10
/* 0DE2C8 80147BC8 AE060000 */  sw    $a2, ($s0)
/* 0DE2CC 80147BCC AE050004 */  sw    $a1, 4($s0)
/* 0DE2D0 80147BD0 AE220000 */  sw    $v0, ($s1)
/* 0DE2D4 80147BD4 26020018 */  addiu $v0, $s0, 0x18
/* 0DE2D8 80147BD8 AE070008 */  sw    $a3, 8($s0)
/* 0DE2DC 80147BDC AE00000C */  sw    $zero, 0xc($s0)
/* 0DE2E0 80147BE0 AE220000 */  sw    $v0, ($s1)
/* 0DE2E4 80147BE4 26020020 */  addiu $v0, $s0, 0x20
/* 0DE2E8 80147BE8 AE090010 */  sw    $t1, 0x10($s0)
/* 0DE2EC 80147BEC AE080014 */  sw    $t0, 0x14($s0)
/* 0DE2F0 80147BF0 AE220000 */  sw    $v0, ($s1)
/* 0DE2F4 80147BF4 26020028 */  addiu $v0, $s0, 0x28
/* 0DE2F8 80147BF8 AE0A0018 */  sw    $t2, 0x18($s0)
/* 0DE2FC 80147BFC AE00001C */  sw    $zero, 0x1c($s0)
/* 0DE300 80147C00 AE220000 */  sw    $v0, ($s1)
/* 0DE304 80147C04 24022CF0 */  addiu $v0, $zero, 0x2cf0
/* 0DE308 80147C08 AE020024 */  sw    $v0, 0x24($s0)
/* 0DE30C 80147C0C 26020030 */  addiu $v0, $s0, 0x30
/* 0DE310 80147C10 24030002 */  addiu $v1, $zero, 2
/* 0DE314 80147C14 AE0B0020 */  sw    $t3, 0x20($s0)
/* 0DE318 80147C18 AE220000 */  sw    $v0, ($s1)
/* 0DE31C 80147C1C 26020038 */  addiu $v0, $s0, 0x38
/* 0DE320 80147C20 AE0C0028 */  sw    $t4, 0x28($s0)
/* 0DE324 80147C24 AE03002C */  sw    $v1, 0x2c($s0)
/* 0DE328 80147C28 AE220000 */  sw    $v0, ($s1)
/* 0DE32C 80147C2C 26020040 */  addiu $v0, $s0, 0x40
/* 0DE330 80147C30 AE030034 */  sw    $v1, 0x34($s0)
/* 0DE334 80147C34 3403FFFE */  ori   $v1, $zero, 0xfffe
/* 0DE338 80147C38 AE0D0030 */  sw    $t5, 0x30($s0)
/* 0DE33C 80147C3C AE220000 */  sw    $v0, ($s1)
/* 0DE340 80147C40 26020048 */  addiu $v0, $s0, 0x48
/* 0DE344 80147C44 AE0E0038 */  sw    $t6, 0x38($s0)
/* 0DE348 80147C48 AE03003C */  sw    $v1, 0x3c($s0)
/* 0DE34C 80147C4C AE220000 */  sw    $v0, ($s1)
/* 0DE350 80147C50 26020050 */  addiu $v0, $s0, 0x50
/* 0DE354 80147C54 AE0F0040 */  sw    $t7, 0x40($s0)
/* 0DE358 80147C58 AE030044 */  sw    $v1, 0x44($s0)
/* 0DE35C 80147C5C AE220000 */  sw    $v0, ($s1)
/* 0DE360 80147C60 0C0187A4 */  jal   osVirtualToPhysical
/* 0DE364 80147C64 AE120048 */   sw    $s2, 0x48($s0)
/* 0DE368 80147C68 8E230000 */  lw    $v1, ($s1)
/* 0DE36C 80147C6C 27A40020 */  addiu $a0, $sp, 0x20
/* 0DE370 80147C70 AE02004C */  sw    $v0, 0x4c($s0)
/* 0DE374 80147C74 3C02E700 */  lui   $v0, 0xe700
/* 0DE378 80147C78 0000302D */  daddu $a2, $zero, $zero
/* 0DE37C 80147C7C 00C0382D */  daddu $a3, $a2, $zero
/* 0DE380 80147C80 0060282D */  daddu $a1, $v1, $zero
/* 0DE384 80147C84 24630008 */  addiu $v1, $v1, 8
/* 0DE388 80147C88 AE230000 */  sw    $v1, ($s1)
/* 0DE38C 80147C8C ACA20000 */  sw    $v0, ($a1)
/* 0DE390 80147C90 240200FF */  addiu $v0, $zero, 0xff
/* 0DE394 80147C94 ACA00004 */  sw    $zero, 4($a1)
/* 0DE398 80147C98 2405FFFF */  addiu $a1, $zero, -1
/* 0DE39C 80147C9C AFA00010 */  sw    $zero, 0x10($sp)
/* 0DE3A0 80147CA0 AFA20014 */  sw    $v0, 0x14($sp)
/* 0DE3A4 80147CA4 AFA00018 */  sw    $zero, 0x18($sp)
/* 0DE3A8 80147CA8 0C051DA6 */  jal   func_80147698
/* 0DE3AC 80147CAC AFA0001C */   sw    $zero, 0x1c($sp)
/* 0DE3B0 80147CB0 8FBF012C */  lw    $ra, 0x12c($sp)
/* 0DE3B4 80147CB4 8FB20128 */  lw    $s2, 0x128($sp)
/* 0DE3B8 80147CB8 8FB10124 */  lw    $s1, 0x124($sp)
/* 0DE3BC 80147CBC 8FB00120 */  lw    $s0, 0x120($sp)
/* 0DE3C0 80147CC0 03E00008 */  jr    $ra
/* 0DE3C4 80147CC4 27BD0130 */   addiu $sp, $sp, 0x130

