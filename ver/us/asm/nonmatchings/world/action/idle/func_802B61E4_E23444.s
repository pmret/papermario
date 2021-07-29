.set noat      # allow manual use of $at
.set noreorder # don't insert nops after branches

glabel func_802B61E4_E23444
/* E23444 802B61E4 27BDFFE0 */  addiu     $sp, $sp, -0x20
/* E23448 802B61E8 AFB00018 */  sw        $s0, 0x18($sp)
/* E2344C 802B61EC 3C108011 */  lui       $s0, %hi(gPlayerStatus)
/* E23450 802B61F0 2610EFC8 */  addiu     $s0, $s0, %lo(gPlayerStatus)
/* E23454 802B61F4 AFBF001C */  sw        $ra, 0x1c($sp)
/* E23458 802B61F8 8E030000 */  lw        $v1, ($s0)
/* E2345C 802B61FC 0461002A */  bgez      $v1, .L802B62A8
/* E23460 802B6200 3C027FFF */   lui      $v0, 0x7fff
/* E23464 802B6204 3442FFFF */  ori       $v0, $v0, 0xffff
/* E23468 802B6208 00621024 */  and       $v0, $v1, $v0
/* E2346C 802B620C 8E030004 */  lw        $v1, 4($s0)
/* E23470 802B6210 2404FFF1 */  addiu     $a0, $zero, -0xf
/* E23474 802B6214 AE020000 */  sw        $v0, ($s0)
/* E23478 802B6218 00441024 */  and       $v0, $v0, $a0
/* E2347C 802B621C A20000B6 */  sb        $zero, 0xb6($s0)
/* E23480 802B6220 A6000008 */  sh        $zero, 8($s0)
/* E23484 802B6224 A60000C0 */  sh        $zero, 0xc0($s0)
/* E23488 802B6228 A60000C2 */  sh        $zero, 0xc2($s0)
/* E2348C 802B622C AE000054 */  sw        $zero, 0x54($s0)
/* E23490 802B6230 30632000 */  andi      $v1, $v1, 0x2000
/* E23494 802B6234 14600013 */  bnez      $v1, .L802B6284
/* E23498 802B6238 AE020000 */   sw       $v0, ($s0)
/* E2349C 802B623C 3C038007 */  lui       $v1, %hi(gGameStatusPtr)
/* E234A0 802B6240 8C63419C */  lw        $v1, %lo(gGameStatusPtr)($v1)
/* E234A4 802B6244 9062007E */  lbu       $v0, 0x7e($v1)
/* E234A8 802B6248 30420010 */  andi      $v0, $v0, 0x10
/* E234AC 802B624C 14400009 */  bnez      $v0, .L802B6274
/* E234B0 802B6250 3C04000C */   lui      $a0, 0xc
/* E234B4 802B6254 90620080 */  lbu       $v0, 0x80($v1)
/* E234B8 802B6258 00021080 */  sll       $v0, $v0, 2
/* E234BC 802B625C 3C04802B */  lui       $a0, %hi(world_action_idle_peachAnims)
/* E234C0 802B6260 00822021 */  addu      $a0, $a0, $v0
/* E234C4 802B6264 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E234C8 802B6268 8C846430 */   lw       $a0, %lo(world_action_idle_peachAnims)($a0)
/* E234CC 802B626C 080AD8AA */  j         .L802B62A8
/* E234D0 802B6270 00000000 */   nop
.L802B6274:
/* E234D4 802B6274 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E234D8 802B6278 3484000E */   ori      $a0, $a0, 0xe
/* E234DC 802B627C 080AD8AA */  j         .L802B62A8
/* E234E0 802B6280 00000000 */   nop
.L802B6284:
/* E234E4 802B6284 8203000C */  lb        $v1, 0xc($s0)
/* E234E8 802B6288 00031040 */  sll       $v0, $v1, 1
/* E234EC 802B628C 00431021 */  addu      $v0, $v0, $v1
/* E234F0 802B6290 000210C0 */  sll       $v0, $v0, 3
/* E234F4 802B6294 3C04800F */  lui       $a0, %hi(world_actions_peachDisguises)
/* E234F8 802B6298 00822021 */  addu      $a0, $a0, $v0
/* E234FC 802B629C 8C847C1C */  lw        $a0, %lo(world_actions_peachDisguises)($a0)
/* E23500 802B62A0 0C0398DB */  jal       peach_set_disguise_anim
/* E23504 802B62A4 00000000 */   nop
.L802B62A8:
/* E23508 802B62A8 8E020004 */  lw        $v0, 4($s0)
/* E2350C 802B62AC 30422000 */  andi      $v0, $v0, 0x2000
/* E23510 802B62B0 1440004C */  bnez      $v0, .L802B63E4
/* E23514 802B62B4 27A40010 */   addiu    $a0, $sp, 0x10
/* E23518 802B62B8 24020001 */  addiu     $v0, $zero, 1
/* E2351C 802B62BC 820300B6 */  lb        $v1, 0xb6($s0)
/* E23520 802B62C0 920500B6 */  lbu       $a1, 0xb6($s0)
/* E23524 802B62C4 10620022 */  beq       $v1, $v0, .L802B6350
/* E23528 802B62C8 28620002 */   slti     $v0, $v1, 2
/* E2352C 802B62CC 10400005 */  beqz      $v0, .L802B62E4
/* E23530 802B62D0 24020002 */   addiu    $v0, $zero, 2
/* E23534 802B62D4 10600009 */  beqz      $v1, .L802B62FC
/* E23538 802B62D8 00000000 */   nop
/* E2353C 802B62DC 080AD8F9 */  j         .L802B63E4
/* E23540 802B62E0 00000000 */   nop
.L802B62E4:
/* E23544 802B62E4 10620022 */  beq       $v1, $v0, .L802B6370
/* E23548 802B62E8 24020003 */   addiu    $v0, $zero, 3
/* E2354C 802B62EC 1062002E */  beq       $v1, $v0, .L802B63A8
/* E23550 802B62F0 27A40010 */   addiu    $a0, $sp, 0x10
/* E23554 802B62F4 080AD8F9 */  j         .L802B63E4
/* E23558 802B62F8 00000000 */   nop
.L802B62FC:
/* E2355C 802B62FC 8E020000 */  lw        $v0, ($s0)
/* E23560 802B6300 30423000 */  andi      $v0, $v0, 0x3000
/* E23564 802B6304 14400037 */  bnez      $v0, .L802B63E4
/* E23568 802B6308 27A40010 */   addiu    $a0, $sp, 0x10
/* E2356C 802B630C 820200C4 */  lb        $v0, 0xc4($s0)
/* E23570 802B6310 14400034 */  bnez      $v0, .L802B63E4
/* E23574 802B6314 00000000 */   nop
/* E23578 802B6318 86020008 */  lh        $v0, 8($s0)
/* E2357C 802B631C 96030008 */  lhu       $v1, 8($s0)
/* E23580 802B6320 28420709 */  slti      $v0, $v0, 0x709
/* E23584 802B6324 14400008 */  bnez      $v0, .L802B6348
/* E23588 802B6328 24620001 */   addiu    $v0, $v1, 1
/* E2358C 802B632C 24A20001 */  addiu     $v0, $a1, 1
/* E23590 802B6330 A20200B6 */  sb        $v0, 0xb6($s0)
/* E23594 802B6334 3C04000C */  lui       $a0, 0xc
/* E23598 802B6338 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E2359C 802B633C 34840003 */   ori      $a0, $a0, 3
/* E235A0 802B6340 080AD908 */  j         .L802B6420
/* E235A4 802B6344 00000000 */   nop
.L802B6348:
/* E235A8 802B6348 080AD8F8 */  j         .L802B63E0
/* E235AC 802B634C A6020008 */   sh       $v0, 8($s0)
.L802B6350:
/* E235B0 802B6350 960200BC */  lhu       $v0, 0xbc($s0)
/* E235B4 802B6354 10400022 */  beqz      $v0, .L802B63E0
/* E235B8 802B6358 3C04000A */   lui      $a0, 0xa
/* E235BC 802B635C 34840001 */  ori       $a0, $a0, 1
/* E235C0 802B6360 24A20001 */  addiu     $v0, $a1, 1
/* E235C4 802B6364 A20200B6 */  sb        $v0, 0xb6($s0)
/* E235C8 802B6368 080AD8F6 */  j         .L802B63D8
/* E235CC 802B636C A6000008 */   sh       $zero, 8($s0)
.L802B6370:
/* E235D0 802B6370 96020008 */  lhu       $v0, 8($s0)
/* E235D4 802B6374 24420001 */  addiu     $v0, $v0, 1
/* E235D8 802B6378 A6020008 */  sh        $v0, 8($s0)
/* E235DC 802B637C 00021400 */  sll       $v0, $v0, 0x10
/* E235E0 802B6380 00021403 */  sra       $v0, $v0, 0x10
/* E235E4 802B6384 284200C9 */  slti      $v0, $v0, 0xc9
/* E235E8 802B6388 14400016 */  bnez      $v0, .L802B63E4
/* E235EC 802B638C 27A40010 */   addiu    $a0, $sp, 0x10
/* E235F0 802B6390 3C04000C */  lui       $a0, 0xc
/* E235F4 802B6394 920200B6 */  lbu       $v0, 0xb6($s0)
/* E235F8 802B6398 34840003 */  ori       $a0, $a0, 3
/* E235FC 802B639C 24420001 */  addiu     $v0, $v0, 1
/* E23600 802B63A0 080AD8F6 */  j         .L802B63D8
/* E23604 802B63A4 A20200B6 */   sb       $v0, 0xb6($s0)
.L802B63A8:
/* E23608 802B63A8 8E020000 */  lw        $v0, ($s0)
/* E2360C 802B63AC 30423000 */  andi      $v0, $v0, 0x3000
/* E23610 802B63B0 10400005 */  beqz      $v0, .L802B63C8
/* E23614 802B63B4 3C04000A */   lui      $a0, 0xa
/* E23618 802B63B8 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E2361C 802B63BC 34840001 */   ori      $a0, $a0, 1
/* E23620 802B63C0 080AD8F8 */  j         .L802B63E0
/* E23624 802B63C4 A20000B6 */   sb       $zero, 0xb6($s0)
.L802B63C8:
/* E23628 802B63C8 960200BC */  lhu       $v0, 0xbc($s0)
/* E2362C 802B63CC 10400004 */  beqz      $v0, .L802B63E0
/* E23630 802B63D0 3C04000C */   lui      $a0, 0xc
/* E23634 802B63D4 34840004 */  ori       $a0, $a0, 4
.L802B63D8:
/* E23638 802B63D8 0C037FBF */  jal       suggest_player_anim_clearUnkFlag
/* E2363C 802B63DC 00000000 */   nop
.L802B63E0:
/* E23640 802B63E0 27A40010 */  addiu     $a0, $sp, 0x10
.L802B63E4:
/* E23644 802B63E4 0C0388C1 */  jal       player_input_to_move_vector
/* E23648 802B63E8 27A50014 */   addiu    $a1, $sp, 0x14
/* E2364C 802B63EC 0C039454 */  jal       phys_update_interact_collider
/* E23650 802B63F0 00000000 */   nop
/* E23654 802B63F4 C7A20014 */  lwc1      $f2, 0x14($sp)
/* E23658 802B63F8 44800000 */  mtc1      $zero, $f0
/* E2365C 802B63FC 00000000 */  nop
/* E23660 802B6400 46001032 */  c.eq.s    $f2, $f0
/* E23664 802B6404 00000000 */  nop
/* E23668 802B6408 45010005 */  bc1t      .L802B6420
/* E2366C 802B640C 24040001 */   addiu    $a0, $zero, 1
/* E23670 802B6410 C7A00010 */  lwc1      $f0, 0x10($sp)
/* E23674 802B6414 A6000008 */  sh        $zero, 8($s0)
/* E23678 802B6418 0C039769 */  jal       set_action_state
/* E2367C 802B641C E6000080 */   swc1     $f0, 0x80($s0)
.L802B6420:
/* E23680 802B6420 8FBF001C */  lw        $ra, 0x1c($sp)
/* E23684 802B6424 8FB00018 */  lw        $s0, 0x18($sp)
/* E23688 802B6428 03E00008 */  jr        $ra
/* E2368C 802B642C 27BD0020 */   addiu    $sp, $sp, 0x20
